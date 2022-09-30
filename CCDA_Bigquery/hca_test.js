var fs = require('fs');
var BlueButton = require('bluebutton');

var xml = fs.readFileSync('./current.xml', 'utf-8');
//var xml = fs.readFileSync('./hl7_expected_ccda.xml', 'utf-8');
//var xml = fs.readFileSync('./CCD_1.xml', 'utf-8');

var ccda = BlueButton(xml);


//console.log(ccda.type.json());
console.log(ccda.data.json());

// Available document sections
// console.log(ccda.data.document.json());
// console.log(ccda.data.allergies.json());
// console.log(ccda.data.care_plan.json());
// console.log(ccda.data.chief_complaint.json());
// console.log(ccda.data.demographics.json());
// console.log(ccda.data.encounters.json());
// console.log(ccda.data.functional_statuses.json());
// console.log(ccda.data.immunizations.json());
// console.log(ccda.data.instructions.json());
// console.log(ccda.data.results.json());
// console.log(ccda.data.medications.json());
// console.log(ccda.data.problems.json());
// console.log(ccda.data.procedures.json());
// console.log(ccda.data.smoking_status.json());
//console.log(ccda.data.vitals.json());

