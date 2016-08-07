// This is a demonstration on how to use an input device to trigger changes on your neo pixels.
// You should wire a momentary push button to connect from ground to a digital IO pin.  When you
// press the button it will change to a new pixel animation.  Note that you need to press the
// button once to start the first animation!

#include <Adafruit_NeoPixel.h>

// These caputre the switch panel inputs
#define BUTTON_PIN0   3    // Digital IO pin connected to the button.  This will be
                          // driven with a pull-up resistor so the switch should
                          // pull the pin to ground momentarily.  On a high -> low
                          // transition the button press logic will execute.
                          // 
#define BUTTON_PIN1   4
#define BUTTON_PIN2   5
#define BUTTON_PIN3   6
#define BUTTON_PIN4   7
#define BUTTON_PIN5   8
#define BUTTON_PIN6   9
#define BUTTON_PIN7   10
#define BUTTON_PIN8   11                      

// Output control to pixels
#define PIXEL_PIN    12    // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 35*12


// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = HIGH;
int showType = 0;

void setup() {
  // Set inputs in pull up mode 
  pinMode(BUTTON_PIN0, INPUT_PULLUP);
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode(BUTTON_PIN5, INPUT_PULLUP);
  pinMode(BUTTON_PIN6, INPUT_PULLUP);
  pinMode(BUTTON_PIN7, INPUT_PULLUP);
  pinMode(BUTTON_PIN8, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Get current switch state.
  int stateNow;
  stateNow = getCurrentState() ;

  switch(stateNow){
    case 0: cloudCircleColor(100, stateNow);    // bottom left
            break;
    case 1: solidWhite(10, stateNow);    // bottom mid
            break;
    case 2: yellowOrangeChase(50, stateNow); 
            break;
    case 3: redBreath(10, stateNow);    // Black/off
            break;
    case 4: cloudCircle(50, stateNow); // White
            break;
    case 5: blueBreath (10, stateNow);
            break;
    case 6: theaterChaseColorRange(50, 85, 85, stateNow);
            break;
    case 7: rainbow(20, stateNow);
            break;
    case 8: rainbowCycle(50, stateNow);
            break;
    default : theaterChaseRainbow(50, stateNow); //If all switches are inactive cool pattern in case stuff breaks
            break;
  }

}

// Checks the current pins versus the current state 
// if they don't match it means a switch has been hit 
bool stateChangeCheck(int currentState) {
    // Sample all of the IOs 
    // LOW means the switch has been switched
    bool newState0 = digitalRead(BUTTON_PIN0);
    bool newState1 = digitalRead(BUTTON_PIN1);
    bool newState2 = digitalRead(BUTTON_PIN2);
    bool newState3 = digitalRead(BUTTON_PIN3);
    bool newState4 = digitalRead(BUTTON_PIN4);
    bool newState5 = digitalRead(BUTTON_PIN5);
    bool newState6 = digitalRead(BUTTON_PIN6);
    bool newState7 = digitalRead(BUTTON_PIN7);
    bool newState8 = digitalRead(BUTTON_PIN8);
    if (newState0 == LOW) {
      return currentState != 0;  // If it's not equal (TRUE) something has changed  
    } else if (newState1 == LOW) {
      return currentState != 1;  // If it's not equal (TRUE) something has changed 
    } else if (newState2 == LOW) {
      return currentState != 2;  // If it's not equal (TRUE) something has changed 
    } else if (newState3 == LOW) { 
      return currentState != 3;  // If it's not equal (TRUE) something has changed 
    } else if (newState4 == LOW) {
      return currentState != 4;  // If it's not equal (TRUE) something has changed 
    } else if (newState5 == LOW) {
      return currentState != 5;  // If it's not equal (TRUE) something has changed 
    } else if (newState6 == LOW) {
      return currentState != 6;  // If it's not equal (TRUE) something has changed 
    } else if (newState7 == LOW) {
      return currentState != 7;  // If it's not equal (TRUE) something has changed 
    } else if (newState8 == LOW) {
      return currentState != 8;  // If it's not equal (TRUE) something has changed 
    } else if (currentState != 9) {
      return true;  // This is state if none of switches are pressed
    } else {
      return false;              // Keep current state
    }
}

// Checks the current pins and determines the current state
int getCurrentState() {
    // Sample all of the IOs 
    // LOW means the switch has been switched
    bool newState0 = digitalRead(BUTTON_PIN0);
    bool newState1 = digitalRead(BUTTON_PIN1);
    bool newState2 = digitalRead(BUTTON_PIN2);
    bool newState3 = digitalRead(BUTTON_PIN3);
    bool newState4 = digitalRead(BUTTON_PIN4);
    bool newState5 = digitalRead(BUTTON_PIN5);
    bool newState6 = digitalRead(BUTTON_PIN6);
    bool newState7 = digitalRead(BUTTON_PIN7);
    bool newState8 = digitalRead(BUTTON_PIN8);
    if (newState0 == LOW) {
      return 0;  // Return the number of the state 
    } else if (newState1 == LOW) {
      return 1;  // Return the number of the state
    } else if (newState2 == LOW) {
      return 2;  // Return the number of the state
    } else if (newState3 == LOW) { 
      return 3;  // Return the number of the state
    } else if (newState4 == LOW) {
      return 4;  // Return the number of the state
    } else if (newState5 == LOW) {
      return 5;  // Return the number of the state
    } else if (newState6 == LOW) {
      return 6;  // Return the number of the state
    } else if (newState7 == LOW) {
      return 7;  // Return the number of the state
    } else if (newState8 == LOW) {
      return 8;  // Return the number of the state
    } else {
      return 9;
    }
}

void rainbow(uint8_t wait, int currState) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
    if (stateChangeCheck(currState)) {
      return;
    }
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait, int currState) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
    if (stateChangeCheck(currState)) {
      return;
    }
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait, int currState) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);
      if (stateChangeCheck(currState)) {
        return;
      } 

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait, int currState) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);
      if (stateChangeCheck(currState)) {
        return;
      } 

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

void solidRed(int delayval, int state) {
    for(int i=0;i<PIXEL_COUNT;i++){ //current disc pixels
      strip.setPixelColor(i, strip.Color(255,0,0)); // Moderately bright green color.
    }  
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    if (stateChangeCheck(state)) {
        return;
     } 

}

void solidWhite(int delayval, int state) {
    for(int i=0;i<PIXEL_COUNT;i++){ //current disc pixels
      strip.setPixelColor(i, strip.Color(100,100,100)); // Moderately bright green color.
    }  
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    if (stateChangeCheck(state)) {
        return;
     } 

}

//discNum function to return what disc we are on
int discNum(int indx) {
  return indx / 12; 
}

  //Theatre-style crawling lights yellow & orange
void yellowOrangeChase(int wait, int state) {
  int n_disc = 0;
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < PIXEL_COUNT; i=i+3) {
            // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
            n_disc = discNum(i);
            if ((n_disc) % 2 == 0) {
               strip.setPixelColor(i +q, strip.Color(252,94,83)); // Red/Orange
            } else {
               strip.setPixelColor(i +q, strip.Color(255, 165,0)); // Yellow / Orange
            }
      }
      strip.show();

      delay(wait);
      if (stateChangeCheck(state)) {
        return;
      }

      for (int i=0; i < PIXEL_COUNT; i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseColorRange(uint8_t wait, int color_width, int color_start, int currState) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, WheelBase( (i+j) % color_width, color_start));    //turn every third pixel on
      }
      strip.show();

      delay(wait);
      if (stateChangeCheck(currState)) {
          return ;
      }

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}


void cloudCircle(int delayval, int currState) {

  int n_disc = 0;

  for(int c=0;c<PIXEL_COUNT;c++){ // chase value    
    for(int i=0;i<PIXEL_COUNT;i++){ //current disc pixels
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 0,255)); // 
      n_disc = discNum(i);
      if ((n_disc - c) % 4 == 0) {
            strip.setPixelColor(i, strip.Color(255, 255,255)); // Cloud Blue
        } else {
            strip.setPixelColor(i, strip.Color(0,0,255)); // Cloud White     
        }
    }
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    if (stateChangeCheck(currState)) {
          return ;
    }
  }
}

void cloudCircleColor(int delayval, int currState) {

  int n_disc = 0;
  for(int outer_color=0;outer_color<PIXEL_COUNT;outer_color++){ // chase value 
  for(int c=0;c<PIXEL_COUNT;c++){ // chase value    
    for(int i=0;i<PIXEL_COUNT;i++){ //current disc pixels
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 0,255)); // 
      n_disc = discNum(i);
      if ((n_disc - c) % 4 == 0) {
            strip.setPixelColor(i, WheelBase( (i+outer_color) % 55, 85)); // Cloud White 
            //strip.setPixelColor(i, strip.Color(255,255,255)); //  
        } else {
            strip.setPixelColor(i, strip.Color(0, 0,255)); //      
        }
    }
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    if (stateChangeCheck(currState)) {
          return ;
    }
  }
  }
}

// Blue Breath - starts dim blue -> brighter blue -> dim blue
void blueBreath (int delayval, int currState) {

    // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    int lower_bness = 30;
    // How many steps of brightness - actually 2x times this given we are going up and down
    int levels = 255 - lower_bness;
    // current brightness level
    int b_level = lower_bness;
  
    // Index goes up and down b levels
    for(int b=0;b<2*levels;b++){
      // decrement from 255 the amount we are above the 255 level - go backwards down in brightness
      if(lower_bness + b < 255) {
        b_level = (b + lower_bness) ;
      } else {
        b_level = 255*2 - (lower_bness + b);
      }
      
      for(int i=0;i<PIXEL_COUNT;i++){
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        strip.setPixelColor(i, strip.Color(0,0,b_level)); // Moderately bright blue color.
    
      }
      strip.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
      if (stateChangeCheck(currState)) {
        return;
      }
    }
}

// Red Breath - starts dim red -> brighter red -> dim red
void redBreath (int delayval, int currState) {

    // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    int lower_bness = 30;
    // How many steps of brightness - actually 2x times this given we are going up and down
    int levels = 255 - lower_bness;
    // current brightness level
    int b_level = lower_bness;
  
    // Index goes up and down b levels
    for(int b=0;b<2*levels;b++){
      // decrement from 255 the amount we are above the 255 level - go backwards down in brightness
      if(lower_bness + b < 255) {
        b_level = (b + lower_bness) ;
      } else {
        b_level = 255*2 - (lower_bness + b);
      }
      
      for(int i=0;i<PIXEL_COUNT;i++){
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        strip.setPixelColor(i, strip.Color(b_level,0,0)); // Moderately bright blue color.
    
      }
      strip.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
      if (stateChangeCheck(currState)) {
        return;
      }
    }
}



// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
// 255 0 0 --> 0, 255,0 --> 0,0,255
// This is a version of the rainbow that is used only to go
// through a certain portion of the color field
uint32_t WheelBase(byte WheelPos, byte wheelStart) {
  WheelPos = 255 - WheelPos + wheelStart;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
