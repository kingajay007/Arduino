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


//Setup
void setup() {
  Serial.begin(115200);
  Serial.println("connect to WiFi network");
  client.begin("APEX", "apex-wifi");
  Serial.println("Setup!");
}

String response;
void loop(){
  response = "";
  int statusCode = client.post("/data", "MotionValue=2&MotionTime=2000", &response);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);
  delay(1000);
}
