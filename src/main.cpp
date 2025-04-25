// D5, D6, D7
// 3V3, GND
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char *ssid = "Redmi 4A";
const char *password = "asep3003";

const int espLed = 2;
const int ledPin1 = 14;
const int ledPin2 = 12;
const int ledPin3 = 13;
const int ledPin5 = 5;
const int ledPin4 = 4;

bool dapurLedState = false;
bool tamuLedState = false;
bool makanLedState = false;
bool toiletLedState = false;
bool halamanLedState = false;

void setDapurLed()
{
  dapurLedState = !dapurLedState;
  digitalWrite(ledPin1, dapurLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void setTamuLed()
{
  tamuLedState = !tamuLedState;
  digitalWrite(ledPin2, tamuLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void setMakanLed()
{
  makanLedState = !makanLedState;
  digitalWrite(ledPin3, makanLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}

void setToiletLed()
{
  toiletLedState = !toiletLedState;
  digitalWrite(ledPin4, toiletLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", toiletLedState ? "ON" : "OFF");
}

void setHalamanLed()
{
  halamanLedState = !halamanLedState;
  digitalWrite(ledPin5, halamanLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", halamanLedState ? "ON" : "OFF");
}

void getDapurLed()
{
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void getTamuLed()
{
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void getMakanLed()
{
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}

void getToiletLed()
{
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", toiletLedState ? "ON" : "OFF");
}

void getHalamanLed()
{
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", halamanLedState ? "ON" : "OFF");
}

void setup()
{
  Serial.begin(115200);

  pinMode(espLed, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to wifi Redmi 4A...");

  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(espLed, HIGH);
    delay(1000);
    Serial.print(".");
  }

  digitalWrite(espLed, LOW);
  Serial.println("");
  Serial.println("Connected to wifi");
  Serial.println(WiFi.localIP());

  server.on("/dapur", HTTP_GET, getDapurLed);
  server.on("/tamu", HTTP_GET, getTamuLed);
  server.on("/makan", HTTP_GET, getMakanLed);
  server.on("/toilet", HTTP_GET, getToiletLed);
  server.on("/halaman", HTTP_GET, getHalamanLed);

  server.on("/dapur", HTTP_POST, setDapurLed);
  server.on("/tamu", HTTP_POST, setTamuLed);
  server.on("/makan", HTTP_POST, setMakanLed);
  server.on("/toilet", HTTP_POST, setToiletLed);
  server.on("/halaman", HTTP_POST, setHalamanLed);

  server.begin();
  Serial.println("Server started...");
}

void loop()
{
  // put your main code here, to run repeatedly:
  server.handleClient();
}