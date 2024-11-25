#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

#define I2C_ADDRESS 0x20
#define TRIAC_REGISTER 0x01
#define SENSOR_REGISTER 0x02

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

WebServer server(80);

struct Device {
  uint8_t triacNumber;
  const char* deviceType;
  const char* model;
  const char* brand;
  float ratedPower;
  float ratedVoltage;
};

Device devices[20] = {
  {1,  "Light",  "Model-L1", "BrandA", 60.0, 220.0},
  {2,  "Fan",    "Model-F1", "BrandB", 75.0, 220.0},
  {3,  "Heater", "Model-H1", "BrandC", 1500.0, 220.0},
  {4,  "AC",     "Model-A1", "BrandD", 2000.0, 220.0},
  {5,  "Light",  "Model-L2", "BrandE", 40.0, 220.0},
  {6,  "Fan",    "Model-F2", "BrandA", 80.0, 220.0},
  {7,  "Heater", "Model-H2", "BrandB", 1200.0, 220.0},
  {8,  "AC",     "Model-A2", "BrandC", 2500.0, 220.0},
  {9,  "Light",  "Model-L3", "BrandD", 55.0, 220.0},
  {10, "Fan",    "Model-F3", "BrandE", 90.0, 220.0},
  {11, "Heater", "Model-H3", "BrandA", 1300.0, 220.0},
  {12, "AC",     "Model-A3", "BrandB", 1800.0, 220.0},
  {13, "Light",  "Model-L4", "BrandC", 70.0, 220.0},
  {14, "Fan",    "Model-F4", "BrandD", 85.0, 220.0},
  {15, "Heater", "Model-H4", "BrandE", 1600.0, 220.0},
  {16, "AC",     "Model-A4", "BrandA", 2300.0, 220.0},
  {17, "Light",  "Model-L5", "BrandB", 65.0, 220.0},
  {18, "Fan",    "Model-F5", "BrandC", 95.0, 220.0},
  {19, "Heater", "Model-H5", "BrandD", 1400.0, 220.0},
  {20, "AC",     "Model-A5", "BrandE", 2100.0, 220.0}
};

void controlTriac(uint8_t triacNumber, bool state) {
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(TRIAC_REGISTER);
  Wire.write(triacNumber);
  Wire.write(state);
  Wire.endTransmission();
}

void readSensorData(uint8_t triacNumber, float& voltage, float& current, float& powerFactor, float& operationalHours) {
  voltage = 220.0 + random(-5, 5);
  current = (devices[triacNumber - 1].ratedPower / voltage) + random(-100, 100) / 1000.0;
  powerFactor = random(60, 100) / 100.0;
  operationalHours = random(1, 24);
}

void handleTriacControl() {
  if (server.hasArg("triac") && server.hasArg("state")) {
    int triacNumber = server.arg("triac").toInt();
    int state = server.arg("state").toInt();

    if (triacNumber >= 1 && triacNumber <= 20 && (state == 0 || state == 1)) {
      controlTriac(triacNumber, state);

      float voltage, current, powerFactor, operationalHours;
      readSensorData(triacNumber, voltage, current, powerFactor, operationalHours);

      StaticJsonDocument<512> jsonDoc;
      Device device = devices[triacNumber - 1];
      jsonDoc["triacNumber"] = triacNumber;
      jsonDoc["state"] = state;
      jsonDoc["deviceType"] = device.deviceType;
      jsonDoc["model"] = device.model;
      jsonDoc["brand"] = device.brand;
      jsonDoc["ratedPower"] = device.ratedPower;
      jsonDoc["ratedVoltage"] = device.ratedVoltage;
      jsonDoc["voltage"] = voltage;
      jsonDoc["current"] = current;
      jsonDoc["powerFactor"] = powerFactor;
      jsonDoc["operationalHours"] = operationalHours;

      String response;
      serializeJson(jsonDoc, response);
      server.send(200, "application/json", response);
    } else {
      server.send(400, "text/plain", "Invalid triac number or state");
    }
  } else {
    server.send(400, "text/plain", "Missing parameters");
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  server.on("/control", handleTriacControl);
  server.begin();
}

void loop() {
  server.handleClient();
}
