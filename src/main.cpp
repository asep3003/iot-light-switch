#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Redmi 4A";
const char *password = "asep3003";

ESP8266WebServer server(80);

const int ledPin = LED_BUILTIN;

String htmlPage()
{
  String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Kontrol LED ESP8266</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      background-color: #1e1e1e;
      color: #f0f0f0;
      padding-top: 50px;
    }
    h1 {
      color: #00ffc3;
    }
    .switch {
      position: relative;
      display: inline-block;
      width: 80px;
      height: 40px;
    }
    .switch input {
      display: none;
    }
    .slider {
      position: absolute;
      cursor: pointer;
      top: 0; left: 0;
      right: 0; bottom: 0;
      background-color: #ccc;
      transition: 0.4s;
      border-radius: 34px;
    }
    .slider:before {
      position: absolute;
      content: "";
      height: 30px;
      width: 30px;
      left: 5px;
      bottom: 5px;
      background-color: white;
      transition: 0.4s;
      border-radius: 50%;
    }
    input:checked + .slider {
      background-color: #00ffc3;
    }
    input:checked + .slider:before {
      transform: translateX(40px);
    }
  </style>
</head>
<body>
  <h1>Kontrol LED NodeMCU 💡</h1>
  <label class="switch">
    <input type="checkbox" onchange="toggleLED(this)">
    <span class="slider"></span>
  </label>

  <script>
    function toggleLED(el) {
      if (el.checked) {
        fetch("/led/on");
      } else {
        fetch("/led/off");
      }
    }
  </script>
</body>
</html>
)rawliteral";
  return html;
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // LED mati (karena LED_BUILTIN aktif low)

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Terhubung! IP address: ");
  Serial.println(WiFi.localIP());

  // Routes
  server.on("/", []()
            { server.send(200, "text/html", htmlPage()); });

  server.on("/led/on", []()
            {
    digitalWrite(ledPin, LOW);  // LED ON (aktif low)
    server.send(200, "text/plain", "LED ON"); });

  server.on("/led/off", []()
            {
    digitalWrite(ledPin, HIGH);  // LED OFF
    server.send(200, "text/plain", "LED OFF"); });

  server.begin();
  Serial.println("Web server aktif.");
}

void loop()
{
  server.handleClient();
}

// D4, D5, D19
// 3V3, GND

// const int ledPin1 = 4;
// const int ledPin2 = 5;
// const int ledPin3 = 19;

// void setup()
// {
//   pinMode(ledPin1, OUTPUT);
//   pinMode(ledPin2, OUTPUT);
//   pinMode(ledPin3, OUTPUT);

//   digitalWrite(ledPin1, HIGH);
//   digitalWrite(ledPin2, LOW);
//   digitalWrite(ledPin3, LOW);
// }

// void loop()
// {
// }