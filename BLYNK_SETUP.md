# 📱 CrowdSense Blynk Setup Guide

This file explains how to set up the Blynk IoT dashboard for **CrowdSense**.

---

## 1️⃣ Create a New Template

1. Open Blynk IoT.
2. Go to **Templates**.
3. Click **New Template**.
4. Enter template name:

```txt
CrowdSense
```

5. Select hardware:

```txt
ESP32
```

6. Select connection type:

```txt
WiFi
```

---

## 2️⃣ Copy Credentials

After creating the template, copy:

- Template ID
- Template Name
- Auth Token

Paste them into your code:

```cpp
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"
```

---

## 3️⃣ Add Datastreams

Create these virtual datastreams:

| Virtual Pin | Name | Data Type |
|---|---|---|
| V0 | People Count | Integer |
| V1 | Temperature | Double / Float |
| V2 | Humidity | Double / Float |
| V3 | Air Quality | Integer |
| V4 | Flame Status | String |

---

## 4️⃣ Suggested Dashboard Widgets

| Widget | Virtual Pin | Purpose |
|---|---|---|
| Label / Gauge | V0 | Shows people count |
| Gauge | V1 | Shows temperature |
| Gauge | V2 | Shows humidity |
| Gauge | V3 | Shows air quality value |
| Label | V4 | Shows SAFE / FIRE status |

---

## 5️⃣ WiFi Setup

Update these lines with your WiFi name and password:

```cpp
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";
```

Make sure your WiFi is **2.4 GHz**, because most ESP32 boards do not connect to 5 GHz WiFi.

---

## 6️⃣ Upload and Test

1. Upload the code to ESP32.
2. Open Serial Monitor at `115200 baud`.
3. Wait for Blynk connection.
4. Open your Blynk dashboard.
5. Test sensors and verify live values.

---

## ✅ Blynk Data Sent by Code

```cpp
Blynk.virtualWrite(V0, count);
Blynk.virtualWrite(V1, temp);
Blynk.virtualWrite(V2, hum);
Blynk.virtualWrite(V3, fakeAir);
Blynk.virtualWrite(V4, "SAFE" or "🔥 FIRE");
```

---

## ⚠️ Note About Fake Air Value

Currently, the air quality value is simulated using:

```cpp
int fakeAir = random(150, 350);
```

This is useful for demonstration when the MQ sensor is not connected or calibrated.

Later, you can replace this with real analog MQ sensor readings.
