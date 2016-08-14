var five = require("johnny-five"), 
    board = new five.Board({ port: "COM4" });

board.on("ready", function() {

   //var motor = new five.motor({
   //   pins: { pwm: 11 },
   //   register: { data: 8, clock: 4, latch: 12 },
   //   bits: { a: 2, b: 3 }
   // }
   // );

   var motors = { 
       M1 :new five.Motor({
       pins: { pwm: 11 },
       register: { data: 8, clock: 4, latch: 12 },
       bits: { a: 2, b: 3 }
   }),
       M2: new five.Motor({
           pins: {
               pwm: 3
           },
           register: {
               data: 8,
               clock: 4,
               latch: 12
           },
           bits: {
               a: 1,
               b: 4
           }
       })
   }
   
   for (index = 1; index < motors.length; index++)
   {
       motors[index].on("start", function () {
           console.log("start", Date.now());

           // Demonstrate motor stop in 2 seconds
           board.wait(12000, function () {
               motors[index].stop();
           });
       });

       motors[index].on("stop", function () {
           console.log("stop", Date.now());
       });

       motors[index].forward(255);
   }


    
      // Motor Event API

  //// "start" events fire when the motor is started.
  //motors.M1.on("start", function() {
  //  console.log("start", Date.now());

  //  // Demonstrate motor stop in 2 seconds
  //  board.wait(12000, function() {
  //    motors.M1.stop();
  //  });
  //});

  //// "stop" events fire when the motor is stopped.
  //motors.M1.on("stop", function() {
  //  console.log("stop", Date.now());
  //});

  // Start the motor at maximum speed
  motors.M1.forward(255);

  motors.M2.forward(255);

  board.wait(12000, function () {
      motors.M1.stop();

      motors.M2.stop();
  });
});