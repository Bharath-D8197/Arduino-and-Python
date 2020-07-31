tinkercad link for alcohol detector project:https://www.tinkercad.com/things/b6KtloQvwjT-alcohol-detector
tinkercad link for lights and fan controlled by ir remote project : https://www.tinkercad.com/things/3cF9qso50cU-ir-remote-with-led


IRremote Library:
<IRremote.h>
IRremote, by Ken Shirriff, allows you to receive or transmit Infrared Remote Control codes. You can make your projects controlled by a remote, or make them control other devices like televisions and stereo components.
Basic Usage
IRremote acts like 2 libraries, one for sending and one for receiving. Usually it's easiest to find the codes to transmit by first using the receiver.
Receiving:
IRrecv irrecv(receivePin)
Create the receiver object, using a name of your choice.
irrecv.enableIRIn()
Begin the receiving process. This will enable the timer interrupt which consumes a small amount of CPU every 50 µs.
irrecv.decode(&results)
Attempt to receive a IR code. Returns true if a code was received, or false if nothing received yet. When a code is received, information is stored into "results".
results.decode_type: Will be one of the following: NEC, SONY, RC5, RC6, or UNKNOWN.
results.value: The actual IR code (0 if type is UNKNOWN)
results.bits: The number of bits used by this code
results.rawbuf: An array of IR pulse times
results.rawlen: The number of items stored in the array
irrecv.resume()
After receiving, this must be called to reset the receiver and prepare it to receive another code.
irrecv.blink13(true)
Enable blinking the LED when during reception. Because you can't see infrared light, blinking the LED can be useful while troubleshooting, or just to give visual feedback.
Transmitting:IRsend irsend;
Create the transmit object. A fixed pin number is always used, depending on which timer the library is utilizing.
irsend.sendNEC(IRcode, numBits);
Send a code in NEC format.
irsend.sendSony(IRcode, numBits);
Send a code in Sony format.
irsend.sendRC5(IRcode, numBits);
Send a code in RC5 format.
irsend.sendRC6(IRcode, numBits);
Send a code in RC6
irsend.sendRaw(rawbuf, rawlen, frequency);
LINKS TO DOWNLOAD IRremote.h:
https://github.com/z3t0/Arduino-IRremote/zipball/master
http://downloads.arduino.cc/libraries/github.com/z3t0/IRremote-2.5.0.zip


LiquidCrystal  library:
<LiquidCrystal.h>
This library allows an Arduino board to control LiquidCrystal displays (LCDs) based on the Hitachi HD44780 (or a compatible) chipset, which is found on most text-based LCDs. The library works with in either 4- or 8-bit mode (i.e. using 4 or 8 data lines in addition to the rs, enable, and, optionally, the rw control lines).
To use this library
#include <LiquidCrystal.h>
•  Autoscroll: Shift text right and left.
•  Blink: Control of the block-style cursor.
•  Cursor: Control of the underscore-style cursor.
•  Display: Quickly blank the display without losing what's on it.
•  Hello World: Displays "hello world!" and the seconds since reset.
•  Scroll: Scroll text left and right.
•  Serial Display: Accepts serial input, displays it.
•  Set Cursor: Set the cursor position.
•  Text Direction: Control which way text flows from the curso
Function
•	LiquidCrystal()
•	begin()
•	clear()
•	home()
•	setCursor()
•	write()
•	print()
•	cursor()
•	noCursor()
•	blink()
•	noBlink()
•	display()
•	noDisplay()
•	scrollDisplayLeft()
•	scrollDisplayRight()
•	autoscroll()
•	noAutoscroll()
•	leftToRight()
•	rightToLeft()
•	createChar()
Link to download LiquidCrystal.h:
http://downloads.arduino.cc/libraries/github.com/arduino-libraries/LiquidCrystal-1.0.7.zip

