# 🔌 CrowdSense Connections Guide

This file explains the wiring connections for the **CrowdSense IoT Crowd Monitoring & Safety System**.

---

## ⚠️ Important Power Note

For basic testing, the ESP32 can be powered using a laptop USB cable.

However, **servo motors can draw high current**, so if your ESP32 resets or LCD flickers, power the servos using a separate 5V supply or LM2596 buck converter.

Always connect **common GND** between ESP32 and external power supply.

---

## 1️⃣ ESP32 to Entry IR Sensor

| IR Sensor Pin | ESP32 Connection |
|---|---|
| VCC | 3.3V or 5V |
| GND | GND |
| OUT | GPIO 27 |

---

## 2️⃣ ESP32 to Exit IR Sensor

| IR Sensor Pin | ESP32 Connection |
|---|---|
| VCC | 3.3V or 5V |
| GND | GND |
| OUT | GPIO 35 |

Note: GPIO 35 is input-only, which is fine for an IR sensor output.

---

## 3️⃣ ESP32 to DHT22 Sensor

| DHT22 Pin | ESP32 Connection |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 4 |

If using a raw DHT22 sensor, add a **10kΩ pull-up resistor** between VCC and DATA.  
Most DHT22 modules already include this resistor.

---

## 4️⃣ ESP32 to Flame Sensor

| Flame Sensor Pin | ESP32 Connection |
|---|---|
| VCC | 3.3V or 5V |
| GND | GND |
| DO | GPIO 33 |

In the code:

```cpp
bool flame = (digitalRead(FLAME_PIN) == LOW);
```

This means flame is detected when the sensor output becomes **LOW**.

---

## 5️⃣ ESP32 to Entry Servo

| Servo Wire | ESP32 / Power Connection |
|---|---|
| Signal | GPIO 18 |
| VCC | 5V |
| GND | GND |

---

## 6️⃣ ESP32 to Exit Servo

| Servo Wire | ESP32 / Power Connection |
|---|---|
| Signal | GPIO 19 |
| VCC | 5V |
| GND | GND |

Servo wire colors usually are:

| Wire Color | Meaning |
|---|---|
| Brown / Black | GND |
| Red | VCC |
| Orange / Yellow | Signal |

---

## 7️⃣ ESP32 to 20×4 I2C LCD

| LCD Pin | ESP32 Connection |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

Default I2C address used in code:

```cpp
LiquidCrystal_I2C lcd(0x27, 20, 4);
```

If the LCD does not display text, try address `0x3F`.

---

## ✅ Final Pin Table

| Component | ESP32 GPIO |
|---|---|
| Entry IR OUT | GPIO 27 |
| Exit IR OUT | GPIO 35 |
| DHT22 DATA | GPIO 4 |
| Flame Sensor DO | GPIO 33 |
| Entry Servo Signal | GPIO 18 |
| Exit Servo Signal | GPIO 19 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |

---

## 🔋 Recommended Power Setup

### For simple demo:

- ESP32 powered from laptop USB
- Sensors powered from ESP32 3.3V/5V
- Servos powered carefully from 5V, only for light testing

### For stable final prototype:

- ESP32 powered from USB or regulated 5V
- Servos powered from external 5V supply
- All grounds connected together

```txt
ESP32 GND ------------- External 5V Supply GND
Servo GND ------------ External 5V Supply GND
Sensor GND ----------- ESP32 GND
```
