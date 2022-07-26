from concurrent.futures.process import _python_exit
from curses.ascii import NUL
from unicodedata import name
from google.cloud import bigquery
import json

class phone(dict):
    def __init__(self, name,phone):
        dict.__init__(self, name=name,phone=phone)
class address(dict):
    def __init__(self, addr,state,zip):
        dict.__init__(self, addr=addr,state=state,zip=zip)
class record(dict):
    def __init__(self, hl7):
        segs = hl7.split("|")
        ph1 = []
        ad1 = []
        if segs[0] == "MSH":
            for m in segs[8].split('^'):
                ph1.append(phone(segs[2],m))
        elif segs[0] == "EVN":
            for m in segs[5].split('^'):
                if m == "": continue
                ad1.append(address(segs[1],segs[2],m))
        dict.__init__(self, type=segs[0],phone=ph1,address=ad1)

# ADT:SEGMENTS&MSH:201601190838:HL7CDMADT:COCQA1A,0001|COCQA1A|MT_COCQA1A_ADT_QA1AGTADM.1.229576.567|J000423598|J500217|J00021004053||^~\&||MT_COCQA1A|||COCQA1A|||DBM||||||||201601190838||ADT|A02|||D|||2.1||||||||||||||||||||||||||||||||||||||||||||||||KYA||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||HL7CDMADT    
# ADT:SEGMENTS&EVN:201601190838:HL7CDMADT:COCQA1A,0002|COCQA1A|MT_COCQA1A_ADT_QA1AGTADM.1.229576.567|J000423598|J500217|J00021004053||A02|201601190838||||||||||||||||||||||||||1TSQBE8554||HAMMOCK|||||BRITTANY||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||HL7CDMADT
# MSH|^~\&|MT_COCQA1A|COCQA1A|DBM||201601190838||ADT^A02|MT_COCQA1A_ADT_QA1AGTADM.1.229576.567|D|2.1||KYA
# EVN|A02|201601190838|||1TSQBE8554^HAMMOCK^BRITTANY^JACK^WARREN^^

ROWS_TO_INSERT = []
# p = [phone("Anand1","444"),phone("Anand2","555")]
# ad = [address("addr1","GA","30021"),address("addr2","CA","52021")]
# a = record("testing",p,ad)
# b = record("testing",p,[])

#ROWS_TO_INSERT.append(json.dumps(a))
ROWS_TO_INSERT.append(json.loads(json.dumps(record("MSH|^~\&|MT_COCQA1A|COCQA1A|DBM||201601190838||ADT^A02|MT_COCQA1A_ADT_QA1AGTADM.1.229576.567|D|2.1||KYA"))))
ROWS_TO_INSERT.append(json.loads(json.dumps(record("EVN|A02|201601190838|||1TSQBE8554^HAMMOCK^BRITTANY^^^^"))))

print(ROWS_TO_INSERT)

# exit

client = bigquery.Client(project='anand-bq-test-2')
table_ref = client.dataset('hca_test').table('hl7pubsub')
table = client.get_table(table_ref)
errors = client.insert_rows_json(table, \
                    ROWS_TO_INSERT)
if errors == []:
    print("New rows have been added.")
else:
    print("Encountered errors while inserting rows: {}".format(errors))