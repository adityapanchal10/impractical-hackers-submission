#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define PIN 10	 // input pin Neopixel is attached to

#define NUMPIXELS      24 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int buttonState = 0;
int stop = 0;
int disp = 0;
long randNumber;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Press the button");
  lcd.setCursor(0,1);
  lcd.print("to spin wheel");
  pinMode(9, INPUT);
  
}

void loop() {
  pixels.begin();
  setColor();
  buttonState = digitalRead(9);
  if (buttonState == HIGH && stop == 0 && disp == 0) {
    for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(delayval);
	}
    if(stop == 0 && disp == 0){
      lcd.clear();
      lcd.print("Press the button");
      lcd.setCursor(0,1);
      lcd.print("to stop wheel");
      disp = 1;
    }
  }
  else if (buttonState == HIGH && stop == 0 && disp == 1){
    randNumber = random(0, 6);
    switch(randNumber){
      case 0:
      	lcd.clear();
      	lcd.print("Resume challenge");
      break;
      case 1:
      	lcd.clear();
      	lcd.print("opensource challenge");
      	break;
      case 2:
      	lcd.clear();
      	lcd.print("friends repo challenge");
      	break;
      case 3:
      	lcd.clear();
      	lcd.print("linkedin challenge");
      	break;
      case 4:
      	lcd.clear();
      	lcd.print("madeup language challenge");
      break;
      case 5:
      	lcd.clear();
      	lcd.print("linux commit challenge");
      	break;
      case 6:
      	lcd.clear();
      	lcd.print("Hackers' choice");
      	break;
    };
    stop = 0;
    disp = 0;
  }
  delay(10);
  
  
}
 
void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}