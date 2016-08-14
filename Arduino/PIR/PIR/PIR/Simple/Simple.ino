#include <Arduino.h>

#include "SoftwareSerial.h"
String ssid = "APEX";
String password = "apex-wifi";
int ledPin = 13;

SoftwareSerial esp(21, 22); // RX, TX

void setup() {
  // put your setup code here, to run once:

  esp.begin(9600);
  
  Serial.begin(9600);
  
  connectWifi();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void connectWifi()
{

  String cmd = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";

  esp.println(cmd);

  delay(4000);

  if (esp.find("OK")) {

    Serial.println("Connected!");
    
    digitalWrite(ledPin, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds
    digitalWrite(ledPin, LOW);   // turn LED ON
    delay(100);
  }

  else {

    connectWifi();

    Serial.println("Cannot connect to wifi");
  }
}
