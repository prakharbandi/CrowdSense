🚶‍♂️ CrowdSense — IoT-Based Real-Time Crowd Monitoring & Safety System (ESP32)

CrowdSense is an ESP32-based smart crowd monitoring and environmental safety system designed to track occupancy levels and monitor surrounding conditions in real time. The system integrates IR-based people counting, temperature & humidity sensing, flame detection, and IoT dashboard visualization using Blynk, making it suitable for smart spaces and safety-aware environments.

The platform also includes automated gate actuation using servo motors, enabling controlled entry and exit monitoring.

🚀 Features
👥 Real-time bidirectional people counting using IR sensors
🌡 Temperature & humidity monitoring (DHT22)
🔥 Flame detection alert system
📊 Live IoT dashboard monitoring using Blynk
🚪 Automatic entry/exit gate actuation via servo motors
📟 20×4 LCD real-time local display
🌐 Wireless monitoring over WiFi (ESP32)
🧠 System Architecture
Entry/Exit IR Sensors
        ↓
ESP32 Controller
        ↓
People Count Logic
        ↓
LCD Display + Servo Gates
        ↓
Environmental Sensors (DHT22 + Flame)
        ↓
Blynk IoT Dashboard (Remote Monitoring)

🛠 Tech Stack

Hardware
ESP32
IR Sensors (Entry + Exit)
DHT22 Temperature & Humidity Sensor
Flame Sensor Module
20×4 I2C LCD Display
Servo Motors (Entry + Exit Gates)
WiFi (onboard ESP32)

Software
Embedded C / Arduino Framework
Blynk IoT Platform
LiquidCrystal_I2C Library
DHT Sensor Library
ESP32 WiFi Stack

📦 Components Used
Component	Purpose
ESP32	Main controller
IR Sensors (×2)	People entry/exit detection
DHT22	Temperature & humidity sensing
Flame Sensor	Fire detection alert
Servo Motors (×2)	Gate control simulation
20×4 LCD	Local monitoring display
Blynk IoT	Remote dashboard visualization

⚙️ Working Principle

CrowdSense tracks occupancy using two IR sensors placed at entry and exit points.

Entry detection → increments count
Exit detection → decrements count
Servo motors simulate automated gate response
Environmental sensors continuously monitor conditions
Data is displayed locally on LCD
Data is transmitted to Blynk dashboard over WiFi

System outputs:

live occupancy count
temperature
humidity
air-quality placeholder values
flame detection alerts

🔌 Basic Pin Connections
IR Sensors
Sensor	ESP32 GPIO
Entry IR	GPIO 27
Exit IR	GPIO 35

Environmental Sensors
Sensor	ESP32 GPIO
DHT22	GPIO 4
Flame Sensor	GPIO 33

Servo Motors
Servo	ESP32 GPIO
Entry Gate Servo	GPIO 18
Exit Gate Servo	GPIO 19

LCD (I2C)
LCD Pin	ESP32
SDA	Default I2C SDA
SCL	Default I2C SCL

(Address used: 0x27)

📊 Blynk Dashboard Mapping

Virtual Pin	Parameter
V0	People Count
V1	Temperature
V2	Humidity
V3	Air Quality (simulated)
V4	Flame Status

📂 Repository Structure
CrowdSense/
│
├── CrowdSense.ino
├── README.md

🎯 Applications
Smart classrooms
auditoriums
libraries
labs
malls
safety monitoring zones
occupancy-aware automation systems

🔬 Future Improvements

Planned upgrades:

real air-quality sensor integration (MQ series)
threshold-based crowd alerts
mobile notification triggers
cloud logging dashboard
camera-assisted crowd estimation
analytics for occupancy trends

👨‍💻 Developed By

Prakhar Bandi Jain
ECE Undergraduate — IET DAVV
Embedded Systems • IoT • Hardware–Software Integration
