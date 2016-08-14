console.log('Init Animatronic !');
var five  = require("johnny-five");
var board = five.Board({ port: "COM4" })
board.on("ready", function() {
  console.log('Board is ready !');
});