#include <Arduino.h>

// Watch video here: https://www.youtube.com/watch?v=35BuobPZu3Y

/* Connection Pins
Arduino    Microphone
 GND          GND
 +5V          +5V
 D3           OUT (or D0) depends on Microphone
*/

int led = 13 ;// define LED Interface
int mic = 12; // define D0 Sensor Interface
int val = 0;// define numeric variables val
 
void setup ()
{
  Serial.begin(9600);
  pinMode (led, OUTPUT) ;// define LED as output interface
  pinMode (mic, INPUT) ;// output interface D0 is defined sensor
}
 
void loop ()
{
  val = digitalRead(mic);// digital interface will be assigned a value of pin 3 to read val
  Serial.println(val);
  if (val == LOW) // When the sound detection module detects a signal, LED flashes
  {
    digitalWrite (led, HIGH);
    Serial.println("ON");
  }
  else
  {
    digitalWrite (led, LOW);
  }
}
