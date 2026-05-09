```text
				            With Love  ⣠⣶⣶⣶⣦⠀⠀
							⠀⠀⣠⣤⣤⣄⣀⣾⣿⠟⠛⠻⢿⣷⠀
							⢰⣿⡿⠛⠙⠻⣿⣿⠁⠀⠀⠀⣶⢿⡇
							⢿⣿⣇⠀⠀⠀⠈⠏⠀⠀⠀ By Junaid
							⠀⠻⣿⣷⣦⣤⣀⠀⠀⠀⠀⣾⡿⠃⠀
							⠀⠀⠀⠀⠉⠉⠻⣿⣄⣴⣿⠟⠀⠀⠀
							⠀⠀⠀⠀⠀⠀⠀⣿⡿⠟⠁⠀⠀⠀⠀
```

# AirQuality-Humidity-PPM-Monitor-using-ESP32

An environmental monitoring system built using ESP32 that tracks:

- Temperature
- Humidity
- Gas concentration (PPM approximation using MQ2)

The system provides real-time monitoring through:
- 16x2 LCD display
- LED indicators
- Buzzer alerts
- Serial Monitor logging

---

## Features

- Real-time temperature and humidity monitoring using DHT22
- Air quality/gas detection using MQ2 sensor
- Automatic baseline gas calibration on startup
- Visual safety indicators using LEDs
- Audible danger alerts using buzzer
- LCD status display
- Serial Monitor diagnostics
- Dynamic threshold comparison for gas detection

---

## Components Used

- ESP32
- DHT22 Sensor
- MQ2 Gas Sensor
- 16x2 LCD Display
- Red LED
- Green LED
- Buzzer
- Jumper wires and breadboard

---

## Pin Configuration

| Component | ESP32 Pin |
|---|---|
| DHT22 Data Pin | GPIO 4 |
| MQ2 Analog Output | GPIO 34 |
| Green LED | GPIO 16 |
| Red LED | GPIO 17 |
| Buzzer | GPIO 18 |

### LCD Pins

| LCD Pin | ESP32 Pin |
|---|---|
| RS | 14 |
| E | 27 |
| D4 | 26 |
| D5 | 25 |
| D6 | 33 |
| D7 | 32 |

---

## Working Principle

### Startup Calibration
On startup, the MQ2 sensor performs automatic calibration by averaging initial readings to determine a baseline gas level.

### Monitoring
The system continuously:
- Reads temperature and humidity from the DHT22 sensor
- Reads gas concentration values from the MQ2 sensor
- Compares values against predefined safety thresholds

### Safety Conditions

Danger mode activates if:

- Temperature > 45°C or < 10°C
- Humidity > 80% or < 20%
- Gas level exceeds calibrated threshold

### Alert System

| Status | Green LED | Red LED | Buzzer |
|---|---|---|---|
| Safe | ON | OFF | OFF |
| Danger | OFF | ON | ON |

---

## Serial Monitor Output

The Serial Monitor displays:
- Temperature
- Humidity
- Gas sensor ADC values
- Current threshold
- Danger status

Example:

```text
Temp: 31.2 C, Humidity: 58 %
Gas ADC: 1450, Threshold: 1380
DANGER ACTIVE: NO
```

---

## Project Structure

```text
AirQuality-Humidity-PPM-Monitor-using-ESP32
├── diagram.json
├── libraries.txt
├── README.md
├── sketch.ino
└── wokwi-project.txt
```

---

## Libraries Used

- LiquidCrystal
- DHT Sensor Library

---

## Future Improvements

- WiFi dashboard integration
- IoT cloud monitoring
- Mobile notifications
- Historical data logging
- Graph-based analytics
- OLED/TFT display support

---

## Simulation

This project can be simulated using Wokwi.

---

## Author

Built by Junaid

