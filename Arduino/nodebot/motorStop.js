var five = require("johnny-five"), 
    board = new five.Board({ port: "COM4" });

board.on("ready", function() {

  var motor = new five.Motor({
      pins: { pwm: 11 },
      register: { data: 8, clock: 4, latch: 12 },
      bits: { a: 2, b: 3 }
    });

  // Start the motor at maximum speed
  motor.stop();

});