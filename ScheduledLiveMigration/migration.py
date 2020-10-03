import time
import requests

METADATA_URL = 'http://metadata.google.internal/computeMetadata/v1/'
METADATA_HEADERS = {'Metadata-Flavor': 'Google'}


def wait_for_maintenance(callback):
    url = METADATA_URL + 'instance/maintenance-event'
    last_maintenance_event = None
    last_etag = '0'

    while True:
        r = requests.get(
            url,
            params={'last_etag': last_etag, 'wait_for_change': True},
            headers=METADATA_HEADERS)

        # During maintenance the service can return a 503, so these should
        # be retried.
        if r.status_code == 503:
            time.sleep(1)
            continue
        r.raise_for_status()
        print(r)
        last_etag = r.headers['etag']

        if r.text == 'NONE':
            maintenance_event = None
        else:
            maintenance_event = r.text

        if maintenance_event != last_maintenance_event:
            last_maintenance_event = maintenance_event
            callback(maintenance_event)


def maintenance_callback(event):
    if event:
        print('Undergoing host maintenance: {}'.format(event))
    else:
        print('Finished host maintenance')


def main():
    wait_for_maintenance(maintenance_callback)


if __name__ == '__main__':
    main()