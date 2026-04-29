# 🛠️ CrowdSense Troubleshooting Guide

Common issues and fixes for the CrowdSense project.

---

## 1️⃣ LCD Shows Nothing

Possible fixes:

- Check LCD VCC and GND.
- Check SDA and SCL connections.
- For ESP32, default I2C pins are:

```txt
SDA = GPIO 21
SCL = GPIO 22
```

- Try changing LCD address:

```cpp
LiquidCrystal_I2C lcd(0x27, 20, 4);
```

to:

```cpp
LiquidCrystal_I2C lcd(0x3F, 20, 4);
```

- Adjust the contrast potentiometer on the I2C LCD module.

---

## 2️⃣ ESP32 Keeps Restarting

Most likely reason: servo motors are drawing too much current.

Fix:

- Use external 5V supply for servos.
- Connect external supply GND with ESP32 GND.
- Do not power heavy servos directly from ESP32 3.3V.

---

## 3️⃣ DHT22 Shows `Err`

Possible fixes:

- Check DHT22 DATA connection to GPIO 4.
- Use 3.3V for DHT22.
- Add 10kΩ pull-up resistor between VCC and DATA if using raw sensor.
- Make sure correct sensor type is selected:

```cpp
#define DHTTYPE DHT22
```

---

## 4️⃣ Flame Sensor Always Shows Fire

Your code uses active-low flame logic:

```cpp
bool flame = (digitalRead(FLAME_PIN) == LOW);
```

If the sensor constantly shows fire:

- Rotate the flame sensor potentiometer slowly.
- Check whether DO output is HIGH normally and LOW during flame.
- Keep the sensor away from strong IR light or sunlight.
- If your module works opposite, change logic to:

```cpp
bool flame = (digitalRead(FLAME_PIN) == HIGH);
```

---

## 5️⃣ IR Sensor Count Increases Randomly

Possible fixes:

- Adjust the IR sensor sensitivity potentiometer.
- Keep the sensor stable and avoid loose wiring.
- Add a small delay after detection if needed.
- Ensure the object properly crosses the sensor beam.

---

## 6️⃣ Blynk Not Connecting

Check these points:

- Template ID is correct.
- Template Name is correct.
- Auth Token is correct.
- WiFi name and password are correct.
- WiFi is 2.4 GHz, not 5 GHz.
- ESP32 has internet access.

---

## 7️⃣ Servo Moving in Wrong Direction

Change the servo angles in code.

Current logic:

```cpp
servoEntry.write(90);
delay(500);
servoEntry.write(0);
```

You can reverse it like this:

```cpp
servoEntry.write(0);
delay(500);
servoEntry.write(90);
```

Or adjust angles based on your gate mechanism.

---

## 8️⃣ Air Quality Value Looks Random

That is expected because the current code uses fake values:

```cpp
int fakeAir = random(150, 350);
```

This is only for dashboard demonstration.

Use a real MQ sensor analog reading later for actual air quality monitoring.
