# IoT Based AQI Monitoring System using ESP32 🌐🌫️

ESP32-based IoT Air Quality Index monitoring system using MQ-135 sensor with local LCD display
and ThingSpeak cloud integration.
# IoT Based Air Quality Index (AQI) Monitoring System using ESP32 🌐🌫️  
Monitor air quality locally and from anywhere.

This project implements a **complete IoT-based Air Quality Index (AQI) monitoring system** using an **ESP32**, **MQ-135 air quality sensor**, visual indicators, an audible alert, a **16x2 LCD display**, and **ThingSpeak cloud integration**.

The system displays air quality data locally and uploads it to the cloud in real time using Wi-Fi.

Smart sensing. Cloud connectivity. Real awareness.

---

## 🧠 Project Overview
Air pollution is a major health concern, especially in indoor environments.  
This system continuously monitors air quality and provides:
- **Local alerts** (LCD, LEDs, buzzer)
- **Remote monitoring** via ThingSpeak cloud

### System Flow


---

## ⚡ Key Features
- Real-time air quality monitoring
- ESP32 high-resolution ADC (0–4095)
- Local LCD display of air value & status
- Audible alert for poor air quality
- Visual indication using LEDs
- Wi-Fi based cloud data upload
- ThingSpeak dashboard support
- Clean and well-commented ESP32 code

Ideal for **IoT academic projects and demonstrations**.

---

## 🔧 Hardware Components
- ESP32 Development Board  
- MQ-135 Air Quality Sensor  
- Buzzer  
- Red LED (Poor air quality)  
- Green LED (Good air quality)  
- 16x2 LCD Display (Parallel mode)  
- Jumper wires and resistors  

⚠️ ESP32 works on **3.3V logic**. Ensure MQ-135 output is ADC-safe.

---

## 🔌 Pin Connections

### MQ-135 Sensor
| MQ-135 Pin | ESP32 GPIO |
|-----------|------------|
| AO | GPIO 34 |
| VCC | 5V |
| GND | GND |

### Output Devices
| Device | ESP32 GPIO |
|------|-----------|
| Buzzer | GPIO 25 |
| Red LED | GPIO 26 |
| Green LED | GPIO 27 |

### LCD (16x2)
| LCD Pin | ESP32 GPIO |
|--------|------------|
| RS | 23 |
| EN | 22 |
| D4 | 21 |
| D5 | 19 |
| D6 | 18 |
| D7 | 5 |


---

## ☁️ Cloud Configuration (ThingSpeak)
1. Create an account on **ThingSpeak**
2. Create a new channel
3. Enable **Field 1**
4. Copy the **Write API Key**
5. Paste it into the ESP32 code:
```cpp

String apiKey = "YOUR_API_KEY";


## Author
Dhruvang Bari
