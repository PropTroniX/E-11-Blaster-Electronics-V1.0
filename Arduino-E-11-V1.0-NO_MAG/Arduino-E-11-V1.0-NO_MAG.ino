/*
   BLTroniX V1.0 Arduino E-11 Blaster Code - 2 Weapons)

   Released:    April 2023
   Author:      www.proptronix.co.uk
   Description: 2 Weapon Arduino Code for a Star Wars E-11 Blaster
   This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
   To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.

   A Special Thank You goes to TK8177 of the Italia Garrison along with András Kun (Protonerd)
   for the idea and files to develop the BLTroniX Blaster Arduino Code.
*/

#include <BLTroniX_Mini_Mp3.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/BLTroniX16pt7b.h>
#include <Fonts/Orbitron_Light8pt7b.h>

// Choose Microcontroller
#define ARDUINO_NANO true         //Un-Comment if Using the Arduino Nano Board
//#define ARDUINO_NANO_EVERY true   //Un-Comment if Using the Arduino Nano Every Board

#define STRIP_PIN 3
#define N_LEDS 25  // Set Number of Pixels

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, STRIP_PIN, NEO_GRB + NEO_KHZ800);

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 32)
#error ("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// 'BlasTech_Logo', 120x27px
const unsigned char BlasTech [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0xff, 0xff, 0xbf, 0xff, 0x80, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x01,
  0xff, 0xff, 0x1f, 0xff, 0x80, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 0xff, 0xe0, 0x00, 0x00,
  0x00, 0x00, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x21, 0xff, 0xf0, 0x00, 0x00, 0x00,
  0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x21, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00,
  0x47, 0xff, 0xe0, 0x08, 0x00, 0x40, 0x00, 0x0c, 0x21, 0xff, 0xfd, 0xc0, 0x01, 0xf0, 0x3f, 0xf7,
  0xff, 0xdf, 0xfc, 0x0f, 0xe7, 0x07, 0x8c, 0x21, 0xe0, 0x7d, 0xc0, 0x01, 0xf0, 0x7f, 0xf0, 0x7c,
  0x1f, 0xfc, 0x3f, 0xe7, 0x07, 0x8c, 0x21, 0xe0, 0x7d, 0xc0, 0x03, 0xf0, 0xff, 0xe0, 0x7c, 0x1f,
  0xf8, 0x7f, 0xc7, 0x07, 0x8c, 0x21, 0xff, 0xf9, 0xc0, 0x03, 0xf8, 0xf0, 0x00, 0x7c, 0x1e, 0x00,
  0x78, 0x07, 0x07, 0x8c, 0x21, 0xff, 0xf9, 0xc0, 0x03, 0xb8, 0xf0, 0x00, 0x7c, 0x1e, 0x00, 0xf0,
  0x07, 0x07, 0x8c, 0x21, 0xff, 0xf9, 0xc0, 0x07, 0xb8, 0x7f, 0xe0, 0x7c, 0x1f, 0xe0, 0xe0, 0x07,
  0xff, 0x8c, 0x21, 0xe0, 0x7d, 0xc0, 0x07, 0xbc, 0x3f, 0xf0, 0x7c, 0x1f, 0xc0, 0xe0, 0x07, 0xff,
  0x8c, 0x21, 0xe0, 0x7d, 0xc0, 0x07, 0xdc, 0x00, 0xf0, 0x7c, 0x1e, 0x00, 0xf0, 0x07, 0x07, 0x8c,
  0x21, 0xff, 0xfd, 0xc0, 0x0f, 0xde, 0x00, 0x70, 0x7c, 0x1e, 0x00, 0xf8, 0x07, 0x07, 0x8c, 0x21,
  0xff, 0xf9, 0xff, 0xef, 0x1e, 0xff, 0xf0, 0x7c, 0x1f, 0xfe, 0x7f, 0xf7, 0x07, 0x8c, 0x21, 0xff,
  0xf1, 0xff, 0xee, 0x0e, 0xff, 0xe0, 0x7c, 0x1f, 0xfe, 0x3f, 0xf7, 0x07, 0x8c, 0x21, 0xff, 0xe1,
  0xff, 0xde, 0x0e, 0xff, 0xc0, 0x78, 0x1f, 0xfe, 0x0f, 0xf7, 0x07, 0x8c, 0x20, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00
};

const int buttonPin = 8;            // selector button
const int buttonPinReload = 7;      // reload button
const int buttonPinFire = 9;        // trigger button

const int laseronPin = 5;           // laser button
const int laseroffPin = 4;          // laser led power

// Laser State
int stateLaseroffPin = LOW;         
int stateLaser;                     
int previousLaser = LOW; 

unsigned long start_hold;
boolean allow = false;
int HOLD_DELAY = 2000;           // Sets the hold delay of switch for LED state change
int sw_laststate = LOW;
long debounce = 200;

int firsttime = 1;
unsigned long startTime;
unsigned long pressTime;

long TrackCounter = 0;
long TrackCounter1 = 0;
long TrackCounter2 = 0;

int buttonPushCounter = 0;       // counter for the number of button presses weapon #1
int buttonState = 0;             // current state of the button
int lastButtonState = 0;         // previous state of the button
int val = 0;                     // status input   pin

int buttonPushCounter1 = 20;     // counter for the number of button presses weapon #2
int buttonState1 = 0;            // current state of the button
int lastButtonState1 = 0;        // previous state of the button
int buttonStateAmmo0 = 0;

int buttonPushCounter2 = 5;
int buttonState2 = 0;
int lastButtonState2 = 0;
int buttonStateAmmo1 = 0;

long time = 0;

void setup() {

  strip.begin();
  strip.show();
  delay(1000);

  pinMode(buttonPin, INPUT);                   // Select Button
  pinMode(buttonPinFire, INPUT);               // Fire Button
  pinMode(buttonPinReload, INPUT);             // Reload Button
  pinMode(laseronPin, INPUT);                  // Laser On
  pinMode(laseroffPin, OUTPUT);                // Laser Off
  digitalWrite(laseroffPin, LOW);              // Laser

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();

  #ifdef ARDUINO_NANO
  {
  Serial.begin(9600);        //Arduino Nano 
  mp3_set_serial (Serial);   //Arduino Nano  
  }
  #endif
   
  #ifdef ARDUINO_NANO_EVERY
  {  
  Serial1.begin(9600);        //Arduino Nano Every
  mp3_set_serial (Serial1);   //Arduino Nano Every 
  }
  #endif
   
  delay(20);
  mp3_reset();
  mp3_set_volume (30);
  delay(500);
  // Begin BlasTech Logo Display
  display.drawBitmap(4, 1, BlasTech, 120, 27, WHITE);
  display.display();
  delay(100);
  // End BlasTech Logo Display
  mp3_play (1);
  delay(3500);
  mp3_play (26);
  delay(2500);
  mp3_play (2);
  display.clearDisplay();
  drawOpenbar ( 0, 0, 128, 32);
  display.setCursor(45, 6);
  display.setTextColor(WHITE);
  display.print(F("BLASTER"));
  display.setCursor(33, 18);
  display.print(F("OPERATIONAL"));
  display.display();
  delay(3000);
  display.clearDisplay();
}

void loop() {
  // Start of Laser Sight
  stateLaser = digitalRead(laseronPin);
  if (stateLaser == HIGH && previousLaser == LOW && millis() - time > debounce) {
    if (stateLaseroffPin == HIGH) {
      stateLaseroffPin = LOW;
      delay (50);
      mp3_play (43);
      display.setFont ();
      display.clearDisplay();
      display.setFont (&Orbitron_Light8pt7b);
      display.setCursor(14, 20);
      display.print(F("LASER OFF"));
      display.display();
      display.clearDisplay();
      delay (2000);
    } else {
      stateLaseroffPin = HIGH;
      delay (50);
      mp3_play (42);
      display.setFont ();
      display.clearDisplay();
      display.setFont (&Orbitron_Light8pt7b);
      display.setCursor(14, 20);
      display.print(F("LASER ON"));
      display.display();
      display.clearDisplay();
      delay (2000);
    }
    time = millis();
  }
  digitalWrite(laseroffPin, stateLaseroffPin);
  previousLaser == stateLaser;
  // End of Laser Sight

  // Start of Select Button
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && sw_laststate == LOW) {
    start_hold = millis();
    allow = true;
  }
  if (allow == true && buttonState == HIGH && sw_laststate == HIGH) {
    if ((millis() - start_hold) >= HOLD_DELAY) {
      mp3_play (27);
      delay (150);
      mp3_play (28);
      display.setFont (&Orbitron_Light8pt7b);
      display.setCursor(32, 20);
      display.print(F("RADIO"));
      display.display();
      delay (3000);
      allow = false;
    }
  }
  if (allow == true && buttonState == LOW && sw_laststate == LOW) {
    if ((millis() - start_hold) < 700 ) {

      mp3_play (4);

      buttonPushCounter++;
      allow = false;
    }
  }
  sw_laststate = buttonState;
  // End of Select Button


  //  ************************************   WEAPONS   ***************************************

  // -------------------------------- WEAPON 1 --- BLASTER --------------------------------

  if (buttonPushCounter == 0) {
    title ();
    display.print(F("BLASTER"));

    if (buttonPushCounter1 > 0) {
      ammo ();
    }
    else if (buttonPushCounter1 == 0) {
      empty ();
    }

    if (buttonPushCounter1 >= 10 ) {
      ammo_count1 ();
      display.print(buttonPushCounter1);
      display.display();
      display.clearDisplay();
    }
    else if (buttonPushCounter1 <= 9 ) {
      ammo_count2 ();
      display.print(buttonPushCounter1);
      display.display();
      display.clearDisplay();
    }

    buttonState1 = digitalRead(buttonPinFire);
    if (buttonState1 == HIGH) {
      if (firsttime == 1) {
        startTime = millis();
        firsttime = 0;
      }
      pressTime = millis() - startTime;
      if (pressTime < 10  ) {
        if (buttonState1 != lastButtonState1) {
          if (buttonState1 == HIGH) {
            buttonPushCounter1 -= 1;
          }
        }
        if (buttonPushCounter1 >= 0) {
          TrackCounter = random(0, 6);

          if ( TrackCounter == 0 )
          {
            mp3_play (7);
          }
          if ( TrackCounter == 1 )
          {
            mp3_play (8);
          }
          if ( TrackCounter == 2 )
          {
            mp3_play (9);
          }
          if ( TrackCounter == 3 )
          {
            mp3_play (10);
          }
          if ( TrackCounter == 4 )
          {
            mp3_play (11);
          }
          if ( TrackCounter == 5 )
          {
            mp3_play (12);
          }
          if ( TrackCounter == 6 )
          {
            mp3_play (13);
          }

          Red_Fire ();

        }
        if (buttonPushCounter1 < 0) {
          delay (500);
          empty_ammo_sound ();
        }
      }
    }
    else if (firsttime == 0) {
      firsttime = 1;
    }
    if (buttonPushCounter1 < 0) buttonPushCounter1 = 0;
    buttonStateAmmo0 = digitalRead(buttonPinReload);
    if (buttonStateAmmo0 == HIGH) {
      buttonPushCounter1 = 20;

      reload_ammo_sound ();
      charge1 ();
    }
  }

  // -------------------------------- WEAPON 2 --- STUN BLASTER --------------------------------

  if (buttonPushCounter == 1) {
    title ();
    display.print(F("STUN BLASTER"));

    if (buttonPushCounter2 > 0) {
      ammo ();
    }
    else if (buttonPushCounter2 == 0) {
      empty ();
    }

    if (buttonPushCounter2 >= 10 ) {
      ammo_count1 ();
      display.print(buttonPushCounter2);
      display.display();
      display.clearDisplay();
    }
    else if (buttonPushCounter2 <= 9 ) {
      ammo_count2 ();
      display.print(buttonPushCounter2);
      display.display();
      display.clearDisplay();
    }

    buttonState2 = digitalRead(buttonPinFire);
    if (buttonState2 == HIGH) {
      if (firsttime == 1) {
        startTime = millis();
        firsttime = 0;
      }
      pressTime = millis() - startTime;
      if (pressTime < 10  ) {
        if (buttonState2 != lastButtonState2) {
          if (buttonState2 == HIGH) {
            buttonPushCounter2 -= 1;
          }
        }
        if (buttonPushCounter2 >= 0) {
          mp3_play (14);

          Stun_Blaster ();

        }
        if (buttonPushCounter2 < 0) {
          delay (500);
          empty_ammo_sound ();
        }
      }
    }
    else if (firsttime == 0) {
      firsttime = 1;
    }
    if (buttonPushCounter2 < 0) buttonPushCounter2 = 0;
    buttonStateAmmo1 = digitalRead(buttonPinReload);
    if (buttonStateAmmo1 == HIGH) {
      buttonPushCounter2 = 5;

      reload_ammo_sound ();
      charge1 ();
    }
  }

  if (buttonPushCounter > 1) {
    buttonPushCounter = 0;
    buttonState = 0;         // current state of the button
    lastButtonState = 0;     // previous state of the button
    val = 0;                 // status input   pin
  }
}

// ********************* END 2 WEAPONS, RESTART VARIABLES *********************


// *********************************** FUNCTIONS *************************

void empty_ammo_sound () {
  mp3_play (5);
  delay(500);
}

void reload_ammo_sound () {
  mp3_play (3);
  delay(500);
}

void charge1 () {
  display.setFont ();
  display.clearDisplay();
  display.setCursor(3, 0);
  display.print(F("CHARGING PLEASE WAIT"));
  bar_graph ();
}

void charge2 () {
  display.setFont ();
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(F("RELOADING PLEASE WAIT"));
  bar_graph ();
}

void drawOpenbar(int x, int y, int width, int height) {
  display.drawRect(x, y, width, height, WHITE);
}

void drawPercentbar(int x, int y, int width, int height) {
  display.drawRect(x, y, width, height, WHITE);
}

void bar_graph () {
  drawPercentbar ( 0, 12, 128, 20);
  display.fillRect(2, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(12, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(22, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(32, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(42, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(52, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(62, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(72, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(82, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(92, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(102, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(112, 14, 10, 16, 1);
  display.display();
  delay(40);
  display.fillRect(122, 14, 2, 16, 1);
  display.display();
  display.clearDisplay();
}

void ammo_count1 () {
  display.setFont (&BLTroniX16pt7b);
  display.drawRect(84, 0, 44, 32, WHITE);   // In, Down, Width, Hight
  display.setCursor(89, 26);
}

void ammo_count2 ()  {
  display.setFont (&BLTroniX16pt7b);
  display.drawRect(84, 0, 44, 32, WHITE);   // In, Down, Width, Hight
  display.setCursor(89, 26);
  display.print("0");
  display.setCursor(107, 26);
}

static void chase(uint32_t c) {   // LED Chase Sequence
  strip.updateLength(25);
  for (uint16_t i = 0; i < strip.numPixels() + 5; i++) {
    strip.setPixelColor(i  , c); // Draw new pixel
    strip.setPixelColor(i - 5, 0); // Erase pixel a few steps back
    strip.show();
    delay(5); // Speed
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i - 1, c);
    strip.show();
    delay(15);
  }
}

void Red_Fire () {
  chase(strip.Color(150, 0, 0)); // Red
  strip.updateLength(25);
  strip.setPixelColor(24, 255, 0, 0);
  strip.show();
  delay(75);
  strip.setPixelColor(24, 0, 0, 0);
  strip.show();
  delay(5);
}

void Stun_Blaster () {
//  strip.updateLength(25);
  colorWipe(strip.Color(0, 0, 150), 10); // Blue
  strip.updateLength(25);
  strip.setPixelColor(24, 0, 0, 255);
  strip.show();
  delay(100);
  strip.setPixelColor(24, 0, 0, 0);
  strip.show();
  delay(10);
  colorWipe(strip.Color(0, 0, 0), 10); // Black
}

void ammo () {
  display.setFont (&Orbitron_Light8pt7b);
  display.setCursor(0, 30);
  display.setTextSize(1);
  display.print(F("AMMO"));
}

void empty () {
  display.setFont (&Orbitron_Light8pt7b);
  display.setCursor(0, 30);
  display.setTextSize(1);
  display.print(F("EMPTY"));
  display.setTextSize(1);
}

void zero() {
  display.setFont (&BLTroniX16pt7b);
  display.drawRect(84, 0, 44, 32, WHITE);   // In, Down, Width, Hight
  display.setCursor(89, 26);
  display.print("0");
  display.setCursor(107, 26);
}

void title () {
  display.setFont ();
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
}
