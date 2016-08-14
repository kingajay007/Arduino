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


#include <RestClient.h>
#include <stdio.h>

int led = 13;
RestClient client = RestClient("http://ajaysskumar-001-site1.etempurl.com:8080");

void setup() {
  // put your setup code here, to run once:

  pinMode(led, OUTPUT);
  Serial.begin(115200);
  client.begin("APEX", "apex-wifi");
}

void loop() {

  String getStr = "/update?api_key=";
  getStr += "ZDH6W8LWXXR0ZYUN";
  getStr += "&motionvalue=";
  getStr += String(random(101, 2000));
  getStr += "&motiontime=";
  getStr += String(random(100, 1000));
  //getStr += "\r\n\r\n";

  //String response = "";
  //int statusCode = client.post("/", &response);
  //int statusCode = client.post("/", "foo=bar");
  //  String response = "";
  //  int statusCode = client.post("/", "foo=bar", &response);
  //   Serial.println(statusCode);
  //   Serial.println(response);

  String response = "";
  int statusCode = client.get("/api/motionsensor/1", &response);
  Serial.println(statusCode);
  Serial.println(response);

  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);   // turn LED ON
  delay(1000);                // delay 100 milliseconds
  digitalWrite(led, LOW);   // turn LED ON
  delay(1000);

}
