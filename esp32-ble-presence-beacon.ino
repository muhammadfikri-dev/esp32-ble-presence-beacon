#include <WiFi.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#define PIN_RELAY 23
#define PIN_LED 2
#define SCAN_TIME_SEC 3

const String TARGET_BLE_MAC = "aa:bb:cc:11:22:33"; // Ganti dengan MAC Beacon / Smartwatch Anda
bool isPresent = false;
unsigned long lastSeenTime = 0;
const unsigned long TIMEOUT_MS = 15000;

BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      String mac = advertisedDevice.getAddress().toString().c_str();
      mac.toLowerCase();
      if (mac == TARGET_BLE_MAC) {
        lastSeenTime = millis();
        if (!isPresent) {
          isPresent = true;
          digitalWrite(PIN_RELAY, LOW); // Turn on lights
          digitalWrite(PIN_LED, HIGH);
          Serial.println("[PRESENCE] User entered room! Lights turned ON.");
        }
      }
    }
};

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RELAY, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_RELAY, HIGH); // OFF

  BLEDevice::init("ESP32-Presence-Hub");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);

  Serial.println("ESP32 BLE Presence Detector Active.");
}

void loop() {
  pBLEScan->start(SCAN_TIME_SEC, false);
  pBLEScan->clearResults();

  if (isPresent && (millis() - lastSeenTime > TIMEOUT_MS)) {
    isPresent = false;
    digitalWrite(PIN_RELAY, HIGH); // Turn off lights
    digitalWrite(PIN_LED, LOW);
    Serial.println("[PRESENCE] User left room! Lights turned OFF.");
  }
}