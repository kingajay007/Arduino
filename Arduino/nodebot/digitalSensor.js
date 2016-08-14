var five = require("johnny-five");
var board = new five.Board({ port: "COM4" });

board.on("ready", function() {

  var sensor = new five.Sensor.Digital(12);

  sensor.on("change", function(value) {
    console.log(value);
  });
});