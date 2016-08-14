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

RestClient client = RestClient("https://api.thingspeak.com");

 

//Setup
void setup() {
  Serial.begin(9600);
  Serial.println("connect to WiFi network");
  client.begin("APEX", "apex-wifi");
  Serial.println("Setup!");
}

String response;
void loop(){

String getStr = "api_key=";
  getStr += "ZDH6W8LWXXR0ZYUN";
  getStr += "&motionvalue=";
  getStr += String(random(101, 2000));
  getStr += "&motiontime=";
  getStr += String(random(100, 1000));
  
  String response = "";
  int statusCode = client.post("/update","api_key=ZDH6W8LWXXR0ZYUN&motionvalue=3000&motiontime=1000", &response);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);
  delay(1000);
}
