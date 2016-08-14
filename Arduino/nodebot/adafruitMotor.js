var five = require("johnny-five"), 
    board = new five.Board({ port: "COM4" });

board.on("ready", function() {

   var motor = new five.Motor({
      pins: { pwm: 11 },
      register: { data: 8, clock: 4, latch: 12 },
      bits: { a: 2, b: 3 }
    });
	
	  // Motor Event API

  // "start" events fire when the motor is started.
  motor.on("start", function() {
    console.log("start", Date.now());

    // Demonstrate motor stop in 2 seconds
    board.wait(12000, function() {
      motor.stop();
    });
  });

  // "stop" events fire when the motor is stopped.
  motor.on("stop", function() {
    console.log("stop", Date.now());
  });

  // Start the motor at maximum speed
  motor.forward(255);

});