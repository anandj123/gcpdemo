/**
 * A transform which adds a field to the incoming data.
 * @param {string} inJson
 * @return {string} outJson
 */
function transform(input) {
	var output = {};
	output.date = input.substring(0,15);
	var rest = input.substring(16,input.length).trim();
	output.system = rest.split(" ")[0].trim();
	rest = rest.substring(rest.indexOf(" "), rest.length).trim();
	output.application = rest.split(" ")[0].trim();
	rest = rest.substring(rest.indexOf(" "), rest.length).trim();
  	output.message = rest;
  	return output;
}