/*
 * created by Rui Santos, http://randomnerdtutorials.com
 *
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */

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
#include "RestClient.h"

RestClient client = RestClient("ajaysskumar-001-site1.etempurl.com");

int redLed = 12;                // the pin that the LED is atteched to
int greenLed = 13;                // the pin that the LED is atteched to
int sensorPin = 17;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;
float analogVal = 0;
int motion = 0;

float temperature;

void setup() {
  //Serial Port begin
  Serial.begin (115200);

  pinMode(greenLed, OUTPUT);      // initalize LED as an output
pinMode(redLed, OUTPUT);      // initalize LED as an output
  Serial.println("connect to WiFi network");
  client.begin("APEX", "apex-wifi");
  Serial.println("Setup!");
}

void loop()
{
  temperature = getTemperature(sensorPin);
  if (temperature>33.00)
  {
    digitalWrite(redLed,HIGH);  
  }
  if (temperature<=33.00)
  {
    digitalWrite(greenLed,HIGH);  
  }
  postData();
  digitalWrite(redLed,LOW);  
  digitalWrite(greenLed,LOW);  
  
  delay(20000);
}

void postData() {
  String url = "/api/motionsensor?MotionValue=" + String(temperature) + "&MotionTime=" + String(temperature);
  String response;
  response = "";
  int statusCode = client.post(url.c_str(), "");
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  //  Serial.print("Response body from server: ");
  //  Serial.println(response);
}

float getTemperature(int sensorPin)
{
  val = analogRead(sensorPin);
  float mv = ( val / 1024.0) * 3300;
  float cel = mv / 10;
  // farh = (cel*9)/5 + 32;

  //float temp = val*0.322265625;

  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  return cel;
}


