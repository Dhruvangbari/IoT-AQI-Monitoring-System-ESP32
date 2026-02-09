/*
 IoT Based Air Quality Index (AQI) Monitoring System using ESP32
*/

#include <WiFi.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(23, 22, 21, 19, 18, 5);

const int airSensorPin = 34;
const int buzzerPin = 25;
const int redLed = 26;
const int greenLed = 27;

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
const char* server = "api.thingspeak.com";
String apiKey = "YOUR_API_KEY";

WiFiClient client;

int airValue = 0;
int threshold = 2000;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("IoT AQI MONITOR");
  lcd.setCursor(0, 1);
  lcd.print("WiFi Connecting");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  lcd.clear();
  lcd.print("WiFi Connected");
  delay(2000);
  lcd.clear();
}

void loop() {
  airValue = analogRead(airSensorPin);

  lcd.setCursor(0, 0);
  lcd.print("Air Value:");
  lcd.print(airValue);
  lcd.print(" ");

  if (airValue > threshold) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: POOR ");
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: GOOD ");
  }

  if (client.connect(server, 80)) {
    String url = "/update?api_key=" + apiKey + "&field1=" + String(airValue);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");
    client.stop();
  }

  delay(15000);
}
