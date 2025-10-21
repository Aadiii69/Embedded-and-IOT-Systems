//Week 6 Lecture 2
// LDR with OLED and OLED display with Temperature Humidity Combined
//23-NTU-CS-1057     M.ADEEL ZIA

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN    14     
#define DHTTYPE DHT11   
#define LDR_PIN 34
#define SDA_PIN 21
#define SCL_PIN 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Temperature Humidity
  Serial.println("Hello, ESP32!");

  Wire.begin(SDA_PIN, SCL_PIN);


  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Initializing...");
  display.display();

  dht.begin();
  delay(1000);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int adcValue = analogRead(LDR_PIN);
  float voltage = (adcValue / 4095.0) * 3.3;

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Error reading DHT22 sensor!");
    return;
  }

  

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("LDR Detection\n");
  Serial.printf("\n\n\nADC: %d  |  \nVoltage: %.2f V\n", adcValue, voltage);
  display.print("\nLDR ADC: "); display.println(adcValue);
  display.print("\nVoltage: "); display.print(voltage, 2); display.println(" V");
  display.display();
delay(1000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Temp & Humidity");

  display.setCursor(0, 16);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");
  display.setCursor(0, 32);
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");
  display.display();

  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(1000);

}