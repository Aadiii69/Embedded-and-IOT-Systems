// WEEK 4 HOME TASK
// OLED Display

// M.ADEEL ZIA     23-NTU-CS-1057

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const float PI_F = 3.1415926;

void setup() {
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for (;;);
  }
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();

  int cx = 48;
  int cy = 24;
  int r = 14;

  display.fillCircle(cx, cy, r, SSD1306_WHITE);

  display.fillRoundRect(cx + r - 2, cy - 4, 16, 10, 3, SSD1306_WHITE);
  display.fillRect(cx + r + 14, cy - 6, 2, 6, SSD1306_WHITE);
  display.fillRect(cx + r + 11, cy - 8, 2, 6, SSD1306_WHITE);
  display.fillRect(cx + r + 8, cy - 9, 2, 6, SSD1306_WHITE);
  display.fillRect(cx + r + 5, cy - 8, 2, 6, SSD1306_WHITE);

  display.drawLine(cx + r + 18, cy - 12, cx + r + 26, cy - 16, SSD1306_WHITE);
  display.drawLine(cx + r + 14, cy - 10, cx + r + 22, cy - 14, SSD1306_WHITE);

  display.fillCircle(cx - 5, cy - 4, 2, SSD1306_BLACK);
  display.fillCircle(cx + 5, cy - 4, 2, SSD1306_BLACK);

  int smR = 8;
  for (int a = 200; a <= 340; a += 6) {
    float rad = a * PI_F / 180.0;
    int x = cx + (int)(smR * cos(rad));
    int y = cy + (int)(smR * sin(rad) + 3);
    display.drawPixel(x, y, SSD1306_BLACK);
  }

  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(1, 5);
  display.println("Attention!");
  display.drawRect(0, 0, 60, 16, SSD1306_WHITE);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 26);
  display.println("M.ADEEL ZIA");
  display.drawRect(15, 22, 80, 22, SSD1306_WHITE);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 26);
  display.println("23-NTU-CS-1057");
  display.drawRect(5, 22, 100, 22, SSD1306_WHITE);
  display.display();
  delay(2000);
}

