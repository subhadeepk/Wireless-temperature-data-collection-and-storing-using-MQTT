#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "max6675.h"
#include <ArduinoJson.h>
int thermoCLK = 2;
int thermoCS = 0;
int thermoDO = 4;
float temp;



MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

// WiFi
const char *ssid = "KOLEY"; // Enter your WiFi name
const char *password = "bubaititu";  // Enter WiFi password
// MQTT Broker
const char *mqtt_broker = "192.168.0.105"; // Enter your WiFi or Ethernet IP
const char *topic1 = "thermocouple1/temp;time";

const int mqtt_port = 1883;
WiFiClient espClient;
PubSubClient client(espClient);
void setup() {
 // Set software serial baud to 115200;
 Serial.begin(115200);
 
 // connecting to a WiFi network
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.println("Connecting to WiFi..");
 }
 
 Serial.println("Connected to the WiFi network");
 
 //connecting to a mqtt broker
 client.setServer(mqtt_broker, mqtt_port);
 client.setCallback(callback);
 
 while (!client.connected()) {
 String client_id = "esp8266-client-";
 client_id += String(WiFi.macAddress());
 
 Serial.printf("The client %s connects to mosquitto mqtt broker\n", client_id.c_str());
 
 if (client.connect(client_id.c_str())) {
  Serial.println("Public emqx mqtt broker connected");
 } else {
  Serial.print("failed with state ");
  Serial.print(client.state());
  delay(2000);
 }
}
 
 // publish and subscribe
 client.publish(topic1, "Temperature data From ESP8266!");
 client.subscribe(topic1);

 
}
void callback(char *topic, byte *payload, unsigned int length) {
 Serial.print("Message arrived in topic: ");
 Serial.println(topic1);
 Serial.print("Message:");
 
 for (int i = 0; i < length; i++) {
  Serial.print((char) payload[i]);
 }
 
 Serial.println();
 Serial.println(" - - - - - - - - - - - -");
}
void loop() {
temp= thermocouple.readCelsius();
char buff[7];
dtostrf(temp, 5, 2, buff);
  
unsigned long num = millis(); 
char mystr[15]; 
sprintf(mystr," %lu",num);
 char dest[24];
 strcpy(dest, buff);
  strcat(dest, ";");
  strcat(dest, mystr);

  client.publish(topic1, dest,true);
// client.subscribe(topic);
 delay(1000);
}
