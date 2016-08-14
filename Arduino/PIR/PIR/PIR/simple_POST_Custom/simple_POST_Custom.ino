#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

/* RestClient simple GET request
 *
 * by Fabiano França (fabianofranca)
 */

#include "RestClient.h"

RestClient client = RestClient("ajaysskumar-001-site1.etempurl.com");

int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;
float analogVal = 0;
int motion =0;

//Setup
void setup() {
  Serial.begin(115200);

  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input

  Serial.println("connect to WiFi network");
  client.begin("APEX", "apex-wifi");
  Serial.println("Setup!");
}

String response;
void loop() {

  val = digitalRead(sensor);  // read sensor value
  //analogVal = analogRead(sensor);
  analogVal = 1023;
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);// turn LED ON
    motion=1;
    postData();
    delay(100);                // delay 100 milliseconds

    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH;       // update variable state to HIGH
    }
  }
  else {
    
    digitalWrite(led, LOW); // turn LED OFF
    //motion=0;
    //postData();
    delay(200);             // delay 200 milliseconds

    if (state == HIGH) {
      
      Serial.println("Motion stopped!");
      state = LOW;       // update variable state to LOW
    }
  }
}

void postData(){
    //String postData = "MotionValue="+String(motion)+"&MotionTime="+String(analogVal);

  String url = "/api/motionsensor?MotionValue="+String(motion)+"&MotionTime="+String(analogVal);

 //client.setHeader("Content-Type: application/x-www-form-urlencoded");
  
  response = "";
  int statusCode = client.post(url.c_str(), "", &response);
  //Serial.print("Data posted: ");
  //Serial.println(postData.c_str());
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);
  //delay(10000);
  }
