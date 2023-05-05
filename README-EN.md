# PiPico-Mame-Keyboard
## A Keyboard USB HID implementation for the Raspberry Pi Pico using MAME's default key mappings  
  
<hr>
<h3>How to install:</h3>  
  
  - Connect your PICO to your PC while holding the boot button down;
  - After a new removable drive appears, copy the ["PiPico-Mame-Keyboard.uf2"](https://github.com/ninomegadriver/PiPico-Mame-Keyboard/raw/main/PiPico-Mame-Keyboard.uf2) file to the root of the drive.
  - That's it!
  
<hr>
<h3>How to connect the buttons:</h3>
  
  - This setup follows the GPs from 0 to 28, skipping the missing 23, 24 and 25;
  - Each GP goes to one terminal of your button;
  - One common ground goes to another terminal of all the buttons.
  
<p align=center>  
  
|         KEY         | Pico | Button       |
|---------------------|------|--------------|
|  F2                 | GP0  |  SERVICE     |
|  9                  | GP1  |  TEST        |
|  5                  | GP3  |  COIN1       |
|  6                  | GP2  |  COIN2       |
|  1                  | GP4  |  P1 START    |
|  UP ARROW           | GP5  |  P1 UP       |
|  DOWN ARROW         | GP6  |  P1 DOWN     |
|  LEFT ARROW         | GP7  |  P1 LEFT     |
|  RIGHT ARROW        | GP8  |  P1 RIGHT    |
|  LEFT CTRL          | GP9  |  P1 Button 1 |
|  LEFT ALT           | GP10 |  P1 Button 2 |
|  SPACE              | GP11 |  P1 Button 3 |
|  LEFT SHIFT         | GP12 |  P1 Button 4 |
|  z                  | GP13 |  P1 Button 5 |
|  x                  | GP14 |  P1 Button 6 |
|  2                  | GP15 |  P2 START    |
|  r                  | GP16 |  P2 UP       |
|  f                  | GP17 |  P2 DOWN     |
|  d                  | GP18 |  P2 LEFT     |
|  g                  | GP19 |  P2 RIGHT    |
|  a                  | GP20 |  P2 Button 1 |
|  s                  | GP21 |  P2 Button 2 |
|  q                  | GP22 |  P2 Button 3 |
|  w                  | GP26 |  P2 Button 4 |
|  e                  | GP27 |  P2 Button 5 |
|  h                  | GP28 |  P2 Button 6 |
  
</p>  
<hr>
<h3>Encoder Support:</h3>
  
This code also supports an encoder for the Player 1 LEFT and RIGHT. Connect the encoder as follows:  
  
<p align=center> 
  
| Encoder | Pico |
|---------|------|
| CLK or A| GP8  |
| DT  or B| GP7  |
| +/VCC:  | +3v3 |
| GND:    | GND  |
  
</p>  
  
To active the encoder, hold down (connect it to ground) GP28 at boot.  
  
You can keep both the encoder and the buttons connected at the same time, it won't 
interfere with one another.    
  
<hr>
<h3>How to build the code with your own modifications:</h3>  
  
  - Install Arduino IDE 1.x;
  - Add the "arduino pico" board core.  
    Add this to your File->Preferences->"Additional Boards Manager URLs":  
    https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json  
  
  - Install the "RotaryEncoder" library on Sketch->Include Library->Manage Libraries  
  - Select the right board at Tools->Boards->Raspberry Pi RP2040 Boards  
  - Build and enjoy!  
  
  
  
