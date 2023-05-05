/*
* RaspberryPi Pico Keyboard implementation with MAME's default keymappings
* https://github.com/ninomegadriver/PiPico-Mame-Keyboard
*
* Nino MegaDriver, 2022
* nino@nino.com.br
* http://www.megadriver.com.br
*
* Bear in mind that Mame dosen't have default keys
* for Player2 button 6 and Advance Mame dosen't have
* defaults for Player2 buttons 4, 5 and 6. You'll have
* to configure these on Mame according to this Code
*
* Quick build instructions:
* - Install Arduino IDE 1.x
* - Add the "arduino pico" board core.
*   Add this to your File->Preferences->"Additional Boards Manager URLs":
*   https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
* - Install the "RotaryEncoder" library on Sketch->Include Library->Manage Libraries
* - Select the right board at Tools->Boards->Raspberry Pi RP2040 Boards
* - Build and enjoy!
*
* This code also supports using an Encoder for LEFT/Right. Install it the encoder as follows:
* 
* CLK or A: GP8 (P1 RIGHT)
* DT  or B: GP7 (P1 LEFT)
* +/VCC:    +3v3
* GND:      Any GND pin
* 
* Booting the board with GP28 grounded tells the code to use the encoder
* otherwise, use single buttons.
* 
* You may leave both joystick and the encoder connected at the same time
* it won't interfere with one another.
*
*
*/

// Include the legacy Keyboard library
#include <Keyboard.h>

// Include the RotaryEncoder library
#include <RotaryEncoder.h>

// Encoder Objects
RotaryEncoder *encoder;
RotaryEncoder::Direction currentDirection, lastDirection;
uint8_t encoderActive = 0, encoderKey = 0;
long encoderTimer = 0;
bool useEncoder = false;

// Holds key state;
uint8_t down[29];

// Keys correspondent to each GP:
const uint8_t keys[] = {
    KEY_F2,               // GP0:   SERVICE
    '9',                  // GP1:   TEST 
    '5',                  // GP3:   COIN1
    '6',                  // GP2:   COIN2
    '1',                  // GP4:   P1 START
    KEY_UP_ARROW,         // GP5:   P1 UP
    KEY_DOWN_ARROW,       // GP6:   P1 Down
    KEY_LEFT_ARROW,       // GP7:   P1 LEFT
    KEY_RIGHT_ARROW,      // GP8:   P1 RIGHT
    KEY_LEFT_CTRL,        // GP9:   P1 BTN1
    KEY_LEFT_ALT,         // GP10:  P1 BTN2
    ' ',                  // GP11:  P1 BTN3
    KEY_LEFT_SHIFT,       // GP12:  P1 BTN4
    'z',                  // GP13:  P1 BTN5
    'x',                  // GP14:  P1 BTN6
    '2',                  // GP15:  P2 START
    'r',                  // GP16:  P2 UP
    'f',                  // GP17:  P2 Down
    'd',                  // GP18:  P2 LEFT
    'g',                  // GP19:  P2 RIGHT
    'a',                  // GP20:  P2 BTN1
    's',                  // GP21:  P2 BTN2
    'q',                  // GP22:  P2 BTN3
    0x00,                 // GP23:  No Connection / Skip
    0x00,                 // GP24:  No Connection / Skip
    0x00,                 // GP25:  No Connection / Skip
    'w',                  // GP26:  P2 BTN4
    'e',                  // GP27:  P2 BTN5
    'h',                  // GP28:  P2 BTN6
};



void setup() {
  Keyboard.begin(); // Initialize the Keyboard

  // Set all GP to inputs with pullups
  for(uint8_t i=0;i<sizeof keys;i++) {

    // Skip 23, 24 and 25
    if(i==23 || i==24 || i==25) continue;

    // Set as pullups
    pinMode(i, INPUT_PULLUP);
  }

  // Give it some time to interrupt
  delay(8);
  
  // If GP28 / P2 BTN6 is LOW at startup
  // Treat P1 LEFT/RIGHT as an Encoder
  if(digitalRead(28) == LOW){
    useEncoder = true;
    encoder = new RotaryEncoder(7, 8);
  }

}

void loop() {

  // If using encoder, process it!
  if(useEncoder == true){

    // Process the encoder
    encoder->tick();

    // Get the Current EncoderDirection
    currentDirection = encoder->getDirection();

    
    if(currentDirection == RotaryEncoder::Direction::NOROTATION){ // if it's stopped, trigger a timer to release any arrow press
      if(encoderActive == 1 && micros() > encoderTimer + 100000){ // if it's idle for more than 100ms, release the last arrow key pressed
        Keyboard.release(encoderKey);
        delay(10);
        encoderActive = 0;
        encoderKey = 0;
      }
    }else{
      
      // We're scrolling, so keep the idle timer active
      encoderTimer = micros();
      encoderActive = 1;
      
      if(currentDirection == RotaryEncoder::Direction::CLOCKWISE) { // We're going RIGHT
        if(encoderKey != KEY_RIGHT_ARROW){ // Check if the arrow key is not already pressed
          Keyboard.release(encoderKey);    // Release the last pressed arrow key
          delay(8);                        // Give it some time for the host to compute
          encoderKey = KEY_RIGHT_ARROW;    // Register the new current arrow key
          Keyboard.press(encoderKey);      // And press it!
        }
      }else if(currentDirection == RotaryEncoder::Direction::COUNTERCLOCKWISE) {
        if(encoderKey != KEY_LEFT_ARROW){
          Keyboard.release(encoderKey);
          delay(8);
          encoderKey = KEY_LEFT_ARROW;
          Keyboard.press(encoderKey);
        }
      }
    }  
  }

  // Process all GPs
  for(uint8_t i=0;i<sizeof keys;i++){

    // Skip GPs 23, 24 and 25
    if(i==23 || i==24 || i==25) continue;

    // If using encoder, also skip GPs 7 and 8
    if(useEncoder == true && (i==7 || i == 8)) continue;

    // Process all other GPs
    if(digitalRead(i) == LOW) {
      Keyboard.press(keys[i]);
      down[i] = 1;
    }else if(down[i] = 1){
      Keyboard.release(keys[i]);
      down[i] = 0;
    }
  }

}
