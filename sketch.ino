#include <LiquidCrystal.h>
#include "DHT.h"


#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define MQ2PIN 34


#define GREEN_LED 16
#define RED_LED 17
#define BUZZER 18

LiquidCrystal lcd(14, 27, 26, 25, 33, 32);


int baseline = 0;
bool calibrated = false;

void setup() {
  
  Serial.begin(115200);
  
  
  lcd.begin(16, 2);
  lcd.print("Env Monitor");

  
  dht.begin();

  
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  
  

  delay(2000); 
}

void loop() {

  int gasValue = analogRead(MQ2PIN);
  
  
  static int count = 0;
  static long sum = 0;

  if (!calibrated) {
    sum += gasValue;
    count++;
    if (count >= 10) {
      baseline = sum / 10;
      calibrated = true;
      Serial.print("Baseline calibrated: ");
      Serial.println(baseline);
    }
    delay(500);
    return; 
  }

  
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  
  int threshold = baseline + 30; 

  
  bool gasDanger = gasValue > threshold;
  bool tempDanger = temp > 45 || temp < 10;
  bool humDanger = hum > 80 || hum < 20;

  
  //lcd.clear(); LCD slower than ESP, delay caused
  lcd.setCursor(0,0);
  lcd.print("T:"); lcd.print(temp); lcd.print("C ");
  lcd.print("H:"); lcd.print(hum); lcd.print("%");
   lcd.setCursor(0,1);
  digitalWrite(GREEN_LED, LOW);

  if (gasDanger || tempDanger || humDanger) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, HIGH);
    lcd.print("Danger!");
    

  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, LOW);

    lcd.print("All Safe");
  }

  
  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" C, Humidity: "); Serial.print(hum);
  Serial.print(" %, Gas ADC: "); Serial.print(gasValue);
  Serial.print(", Threshold: "); Serial.println(threshold);
  Serial.print(" | DANGER ACTIVE: ");
  Serial.println(gasDanger || tempDanger || humDanger ? "YES" : "NO");

  delay(5000); 
}