#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);  // 位址 0x27, LCD 16x2
int isFlamePin = 7;
int isFlame = HIGH;

void setup() {
  lcd.init();        // 初始化 LCD
  lcd.backlight();   // 開啟背光

  pinMode(isFlamePin, INPUT);
  Serial.begin(9600);

  // 啟動提示
  lcd.setCursor(0, 0);
  lcd.print("Sensor");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  isFlame = digitalRead(isFlamePin);

  lcd.clear(); // 每次更新前清除螢幕
  if (isFlame == LOW) {
    lcd.setCursor(0, 0);
    lcd.print("FLAME!");
    lcd.setCursor(0, 1);
    lcd.print("FLAME!");
    Serial.println("FLAME!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("No FLAME");
    Serial.println("No FLAME");
  }

  delay(500); // 每 0.5 秒更新一次
}

