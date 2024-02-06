![](https://GalacticProps.co.uk/GitHub/GitHub_Logo.jpg)


------------

##### *Table of Contents*

- [Arduino E-11 Blaster Electronics](#arduino-e-11-blaster-electronics)
- [Video of the Full Version Electronics](#video-of-the-full-version-electronics)
- [Electronics Functions](#electronics-functions)
- [Parts Required](#parts-required)
- [Software Required](#software-required)
- [Wiring Schematics](#wiring-schematics)
- [Programming Instructions](#programming-instructions)
- [SD-Card Sound Files](#sd-card-sound-files)
- [3D Print STL Files](#3d-print-stl-files)
- [Licence](#licence)
- [Donation Button](#donation-button)

### Arduino E-11 Blaster Electronics:

Arduino code for a Star Wars E-11 Blaster. 
This is aa Arduino Project to add lights and sounds to your E-11 Blaster. (Normal Blaster & Stun Blaster)
Relatively easy to build for someone with basic soldering skills using cheap and readily available components.

If your looking for more functions and STL files that better represent a true Sterling Machine Gun then consider having a look at my - [E-11 Blaster Electronics Kit V2](https://proptronix.co.uk/prop-electronics/e-11-stormtrooper-blaster-rifle-electronics-kit "E-11 Blaster Electronics Kit V2")

![](https://www.galacticprops.co.uk/GitHub/E-11_Blaster/GitHub_E-11_1.png)

### Video of the Full Version Electronics:

Check out my Video of a 3D Printed Prototype with the Electronics Installed

YouTube Video - [Star Wars 3D Printed E-11 Blaster with Electronics](https://youtu.be/4NYTuRMlmhI "Star Wars 3D Printed E-11 Blaster with Electronics")

###  Electronics Functions:
**1. Select Button:**
Single Press Changes between the Normal Blaster & Stun Blaster with Sound Effect.\
Long Press plays the Radio Mode Sound File.

***OLED Display:*** Show the Current Selected Weapon or Radio Mode on Long Press

**2. Trigger Switch:**
Blaster Mode - Plays One of 7 Random Blaster Sound Effects with Barrel & Muzzle LED's\
Stun Mode - Plays the Stun Blaster Sound Effect with Barrel & Muzzle LED's

***OLED Display:***Display Current Weapon and Remaining Ammo. No Ammo Blaster Will NOT Fire

**3. Reload Button:**
Single Press Recharges the Blaster Ammo with Sound Effect

***OLED Display:*** Shows Recharging Ammo Bar-graph

**4. Laser Button:**
Press Once to Turn the LED Red Dot Laser On\
Press again to Turn the LED Red Dot Laser Off

***OLED Display:*** Displays Laser Activated or Laser Deactivated

**5. Magazine Switch:**
If Magazine NOT Inserted Blaster will NOT Fire and Weapon Error Voice Sound will Play.\
Insert Magazine - Insert Magazine Sound Effect Played, Blaster Ready to Fire

***OLED Display:*** Shows Weapon Error or Normal Operating Screen when Magazine Inserted.

###  Parts Required:

1 x Set of 3D STLFiles  - For 3D Printing the E-11 Blaster (Included FREE in the Download)

1 x [Arduino Nano V3](https://proptronix.co.uk/arduino_components/microcontrollers/arduino-nano-v3-0 "Arduino Nano V3") - Atmel Atmega328P-AU MCU

1 x [DFPlayer Mini MP3](https://proptronix.co.uk/arduino_components/audio_components/dfplayer_mini_mp3 "DFPlayer Mini MP3") - Requires 1 x 1K Resistors for TX Connection to Arduino Nano

1 x [Micro SD-Card](https://proptronix.co.uk/arduino_components/audio_components/4gb-micro-sd-card "Micro SD-Card") - 2GB or 4GB

1 x [PAM8403 Amplifier](https://proptronix.co.uk/arduino_components/audio_components/pam8403-class-d-amplifier "PAM8403 Amplifier") - Class D Amplifier 2 x 3W

1 x [3W 4Ω Speaker](https://proptronix.co.uk/arduino_components/speakers/3w-4-ohm-speaker-with-lead "3W 4Ω Speaker") - Any 3W 4Ω Speaker that will fit inside the Magazine.

1 x [0.91 OLED Display](https://proptronix.co.uk/arduino_components/oled_displays/0-91-oled-display "0.91 OLED Display") - White OLED Screen Module SSD1306 Drive IC 128x32 IIC Interface

1 x [Red Laser Dot Diode](https://proptronix.co.uk/arduino_components/leds/red-dot-laser-diode-led "Red Laser Dot Diode") - 650nm 6mm 3V-5V (Optional)

1 x [Mini Micro Lever Switch](https://proptronix.co.uk/other_components/switches/micro-limit-lever-switch " Mini Micro Lever Switch") - Micro Lever Switch for Trigger

2 x [6x6x7mm Tactile Momentary Switch](https://proptronix.co.uk/other_components/switches/6mm-tactile-switch "6x6x7mm Tactile Momentary Switch") - Weapon Select & Laser On/Off Switches

1 x [6x4mm Momentary Tactile Switch](https://proptronix.co.uk/other_components/switches/6x4x5-mm-tactile-switch "6x4mm Momentary Tactile Switch") - Hengstler Blaster Reload Switch

1 x [Magnetic Reed Switch](https://proptronix.co.uk/other_components/switches/magnetic-reed-switch "Magnetic Reed Switch") - Magazine Out Detection Switch (Requires a Magnet to Work)

1 x [Single WS2812B LED](https://proptronix.co.uk/arduino_components/leds/single-rgb-neopixel-led "Single WS2812B LED") - Fire LED

1 x [Strip of 24 WS2912B LEDs](https://proptronix.co.uk/arduino_components/leds/e-11-blaster-neopixel-strip "Strip of 24 WS2912B LEDs") - Barrel LED's

1 x [TP4056 Battery Charge Board](https://proptronix.co.uk/other_components/battery_circuit_boards/usb-battery-charger-tp4056 "TP4056 Battery Charge Board") - For Charging the 3.7V 18650 Battery

5 x [10K Ω Resistor](https://proptronix.co.uk/other_components/resistors/1-4w-carbon-film-resistors "10K Ω Resistor") - Trigger, Reload, Select, Laser & Magazine Switches

1 x [1K Ω Resistor](https://proptronix.co.uk/other_components/resistors/1-4w-carbon-film-resistors "1K Ω Resistor") - Needed between DFPlayer RX & Arduino Nano TX

All parts listed above are available from my [Online Shop](https://proptronix.co.uk "Online Shop") , eBay, Amazon or AliExpress.

I also sell the updated [E-11 Blaster Electronics Kit V2.0](https://proptronix.co.uk/prop-electronics/e-11-stormtrooper-blaster-rifle-electronics-kit "E-11 Blaster Electronics Kit V2.0") as a Self Build or Pre-Built Kit in my Shop. It has more weapons with improved code and also utilises a PCB Board to make construction and installation much easier.

***Optional Blaster PCB:*** Makes the installation a lot easier and more compact

[E-11 BLTroniX PCB V2.0](https://proptronix.co.uk/prop-components/e-11_blaster_components/e-11-bltronix-pcb-v2-0 "E-11 BLTroniX PCB V2.0")

###  Software Required:

You will need the following Software & Libraries to install and setup the E-11 Blaster Arduino Code on the Arduino Nano V3.
- The latest version of Arduino IDE - [Download from the Arduino Site](https://www.arduino.cc/en/Main/Software "Download from the Arduino Site")

Arduino Libraries Needed:

- BLTroniX Mini Mp3 - Included in the Download
- Adafruit SSD1306 - Included in the Download and Pre-Set for 128x32 OLED Display
- Adafruit GFX - Included in the Download
- BLTroniX16pt7b Font - Included in the Download and pre loaded in Adafruit GFX Fonts
- Orbitron_Light8pt7b Font - Included in the Download and pre loaded in Adafruit GFX Fonts

BLTroniX V1.0 Arduino E-11 Blaster Code:

- Arduino_E-11-V1.0.ino - Included in the Download

###  Wiring Schematics:

[![Wiring Schematics](https://www.galacticprops.co.uk/GitHub/E-11_Blaster/GitHub_E-11_Schematics1.png "Wiring Schematics")](https://www.galacticprops.co.uk/GitHub/E-11_Blaster/GitHub_E-11_Schematics1.png "Wiring Schematics")

###  Programming Instructions:

1. Copy the Three Included Libraries:\
BLTroniX_Mini_Mp3,\
Adafruit_GFX_Library,\
Adafruit_SSD1306-master_64x32),\
into your Arduino Libraries Folder.

2. Run the Arduino IDE Application

3. File Open and locate the Arduino_E-11-V1.0 Directory and open the Load the Arduino_E-11-V1.0.ino file.

4. Select Tools: Select: and Board and select Arduino Nano

5. Select Tools: Port: and Select the COM Port your Arduino Nano board is plugged in to.

6. Select Tools: Programmer: and choose AVRISP mkII.

7. Upload the Arduino_E-11-V1.0.ino code to the board

You should now have a functioning E-11 Blaster with Lights and Sounds

### SD-Card Sound Files:

- Weapon Initialising - Voice Sound - "Please Wait Weapon Systems Initialising"
- Fully Operational - Voice Sound File - "Your BlasTech Weapon is Fully Operational"
- Reload Sound - Sound Effect
- Change Weapon - Sound Effect
- Weapon Empty Sound - Sound Effect
- E-11 Blaster Blast Sound - Sound Effect - 7 Different Blaster Sounds Played Randomly
- E-11 Blaster Stun Sound - Sound Effect
- Startup Sound - Sound Effect
- Radio Mode Start Sound - Sound Effect
- Radio Chatter Sound - Voice Sound File - Radio Background Chatter
- Magazine Loaded Sound - Sound Effect
- No Magazine Sound - Voice Sound - "Warning Weapon Error"
- Laser Sight/Scope On - Voice Sound File - "Laser Sight Activated"/"Scope Activated"
- Laser Sight/Scope Off - Voice Sound File - "Laser Sight Deactivated"/"Scope Deactivated"

All sound files are stored in a folder named mp3 which is transferred to the Micro SD-Card.

***Important**:*
Please  format your Micro SD-Card with the [SD Card Formatter App](https://www.sdcard.org/downloads/formatter/ "SD Card Formatter App")

### 3D Print STL Files:
The download also includes a set of E-11 Blaster 3D Printable STL Files.
Some of the parts have ben modified from the Free Files that are available from [My Mini Factory](https://www.myminifactory.com/object/3d-print-star-wars-storm-trooper-blastech-e-11-blaster-rifle-by-blaster-master-72283 "My Mini Factory") by Raymond Hebert. to hold the Electronics but not all parts so some modifications will still need to be made.

You can use the included E-11 Blaster Build Instructions provided by Raymond Hebert for his E-11 Blaster Build to help build the included E-11 Blaster 3D Printer STL Files.

![](https://GalacticProps.co.uk/GitHub/E-11_Blaster/GitHub_Trigger_Switches.jpg)

###  Licence:

This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
To view a copy of this license, visit https://creativecommons.org/licenses/by-nc/4.0/


### Donation Button:
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/donate/?hosted_button_id=PEK9F5JV4Q6NL) Please feel free to donate a cup of coffee if you find this code useful. Thank You
