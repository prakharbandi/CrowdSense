// ================= BLYNK CONFIG =================
// Replace these with your own credentials before running locally

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// ================= WIFI =================
// Replace with your WiFi credentials

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// ================= PINS =================

#define IR_ENTRY 27 
#define IR_EXIT 35
#define DHTPIN 4
#define DHTTYPE DHT22
#define FLAME_PIN 33

#define SERVO_ENTRY_PIN 18
#define SERVO_EXIT_PIN 19

// ================= OBJECTS =================

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 20, 4);

Servo servoEntry;
Servo servoExit;

// ================= VARIABLES =================

int count = 0;

bool entryPrev = HIGH;
bool exitPrev = HIGH;

// ================= SETUP =================

void setup() {

  Serial.begin(115200);

  pinMode(IR_ENTRY, INPUT);
  pinMode(IR_EXIT, INPUT);
  pinMode(FLAME_PIN, INPUT);

  dht.begin();

  lcd.init();
  lcd.backlight();

  servoEntry.attach(SERVO_ENTRY_PIN);
  servoExit.attach(SERVO_EXIT_PIN);

  servoEntry.write(0);
  servoExit.write(0);

  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(1500);
  lcd.clear();

  // -------- BLYNK --------
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// ================= LOOP =================

void loop() {

  Blynk.run();  // REQUIRED

  bool entryNow = digitalRead(IR_ENTRY);
  bool exitNow = digitalRead(IR_EXIT);

  // -------- ENTRY --------
  if (entryPrev == HIGH && entryNow == LOW) {

    count++;

    servoEntry.write(90);
    delay(500);
    servoEntry.write(0);
  }

  // -------- EXIT --------
  if (exitPrev == HIGH && exitNow == LOW) {

    if (count > 0) count--;

    servoExit.write(90);
    delay(500);
    servoExit.write(0);
  }

  entryPrev = entryNow;
  exitPrev = exitNow;

  // -------- SENSOR DATA --------

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int fakeAir = random(150, 350);
  bool flame = (digitalRead(FLAME_PIN) == LOW);

  // -------- LCD --------

  lcd.setCursor(0, 0);
  lcd.print("People: ");
  lcd.print(count);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");

  if (!isnan(temp)) {

    lcd.print(temp);
    lcd.print("C   ");

  } else {

    lcd.print("Err   ");
  }

  lcd.setCursor(0, 2);
  lcd.print("Hum:");

  if (!isnan(hum)) {

    lcd.print(hum);
    lcd.print("% ");

  } else {

    lcd.print("Err ");
  }

  lcd.print("Air:");
  lcd.print(fakeAir);
  lcd.print("   ");

  lcd.setCursor(0, 3);

  if (flame) {

    lcd.print("FLAME ALERT! ");

  } else {

    lcd.print("No Flame     ");
  }

  // -------- BLYNK SEND --------

  Blynk.virtualWrite(V0, count);
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, hum);
  Blynk.virtualWrite(V3, fakeAir);

  if (flame) {

    Blynk.virtualWrite(V4, "🔥 FIRE");

  } else {

    Blynk.virtualWrite(V4, "SAFE");
  }

  delay(200);
}