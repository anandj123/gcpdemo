/**
 * A transform which adds a field to the incoming data.
 * @param {string} inJson
 * @return {string} outJson
 */
function transform(inJson) {
  var obj = JSON.parse(inJson);
  obj.dataFeed = "Real-time Transactions";
  obj.dataSource = "POS";
  return JSON.stringify(obj);
}