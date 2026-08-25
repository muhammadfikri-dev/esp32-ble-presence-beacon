# 🚀 ESP32 BLE Room Presence Detector & Smart Light Automation

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: ESP32](https://img.shields.io/badge/Platform-ESP32-blue.svg)](https://espressif.com/)
[![Framework: Arduino IDE](https://img.shields.io/badge/Framework-Arduino%20IDE-teal.svg)](https://www.arduino.cc/)
[![Category: Smart Home & Automation](https://img.shields.io/badge/Category-Smart%20Home%20&%20Automation-purple.svg)](#)
[![Portfolio: Laksanasoft](https://img.shields.io/badge/Portfolio-Laksanasoft-green.svg)](#)

ESP32 Bluetooth Low Energy (BLE) iBeacon & Smartwatch Presence Tracker with Auto Lighting Control.

---

## 📌 Features & Overview

- **Embedded Controller:** ESP32 Dual-Core Tensilica Xtensa 32-bit LX6 Microcontroller.
- **Wireless Connectivity:** Built-in 2.4 GHz Wi-Fi (802.11 b/g/n) & Bluetooth v4.2 / BLE.
- **Arduino IDE Compatible:** Direct flashing and firmware updates using Arduino IDE or PlatformIO (VS Code).
- **Production-Ready Schematics:** Pre-configured pinouts, sensor calibrations, and robust connection recovery handlers.

---

## 🔌 Hardware Pinout & Wiring Table

```
+--------------------+-----------------------+---------------------+
| ESP32 GPIO Pin     | Target Module Pin     | Function / Protocol |
+--------------------+-----------------------+---------------------+
| GPIO 23 | Relay / Light Trigger | Active LOW |
| GPIO 2 | Built-in Status LED | Indicator |
+--------------------+-----------------------+---------------------+
```

---

## 📁 Repository Structure

```
esp32-ble-presence-beacon/
├── esp32-ble-presence-beacon.ino           # Main Arduino C++ sketch
├── config.h.example      # Wi-Fi / MQTT configuration template
├── .gitignore            # Git ignore rules
├── LICENSE               # MIT Open Source License
└── README.md             # Project documentation
```

---

## 🚀 Quick Setup Guide

1. Buka project di **Arduino IDE** (Versi 2.0+).
2. Pasang board support **ESP32 by Espressif Systems** di Board Manager.
3. Pilih board **ESP32 Dev Module**.
4. Sesuaikan konfigurasi pin atau kredensial Wi-Fi.
5. Klik **Upload**.

---

## 📄 License
Distributed under the **MIT License**. Developed by **Muhammad Fikri** for **Laksanasoft**.
