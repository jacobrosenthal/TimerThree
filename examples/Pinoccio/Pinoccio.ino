/**
This is the Pinoccio Bootstrap sketch from https://github.com/Pinoccio/library-pinoccio
Modified by @JacobRosenthal to be a wrapper for the excellent TimerThree library
from PJRC so you'll need that: http://www.pjrc.com/teensy/td_libs_TimerOne.html

Follow the directions there, but basically after uploading this you'll still have
all your Scout and HQ functions but now you you can call the TimerThree functions
from scoutscript. 
Note: 
You can only use pins 3, 4 and 5
The interrupt functions are not available as they're not set up in Pinoccio yet
Functions are lower case

EX:

timer3.initialize(20); //set up 20ms timer for a servo for instance
timer3.pwm(3, 100); //set duty cycle on pin 3 to 10%

TODO:
Pinoccio is a bit in motion still and theres no way for me to call the pins in
such a way that HQ knows about them and can show their new status in the HQ dashboard :(

This is probably under some license from the Pinoccio guys. Go talk to them.
*/

#include <TimerThree.h>

#include <SPI.h>
#include <Wire.h>
#include <Scout.h>
#include <GS.h>
#include <bitlash.h>
#include <lwm.h>
#include <js0n.h>

#include "version.h"

void setup() {
  addBitlashFunction("timer3.initialize", (bitlash_function)timer3Initialize);
  addBitlashFunction("timer3.setPeriod", (bitlash_function)timer3SetPeriod);
  addBitlashFunction("timer3.start", (bitlash_function)timer3Start);
  addBitlashFunction("timer3.stop", (bitlash_function)timer3Stop);
  addBitlashFunction("timer3.restart", (bitlash_function)timer3Restart);
  addBitlashFunction("timer3.resume", (bitlash_function)timer3Resume);
  addBitlashFunction("timer3.pwm", (bitlash_function)timer3Pwm);
  addBitlashFunction("timer3.setPwmDuty", (bitlash_function)timer3SetPwmDuty);
  addBitlashFunction("timer3.disablePwm", (bitlash_function)timer3DisablePwm);

  Scout.setup(SKETCH_NAME, SKETCH_REVISION, SKETCH_BUILD);
  // Add custom setup code here
}

void loop() {
  Scout.loop();
  // Add custom loop code here
}

void timer3Initialize (){
  Timer3.initialize(getarg(1));
}

void timer3SetPeriod (){
  Timer3.setPeriod(getarg(1));
}

void timer3Start (){
  Timer3.start();
}

void timer3Stop (){
  Timer3.stop();
}

void timer3Restart (){
  Timer3.restart();
}

void timer3Resume (){
  Timer3.resume();
}

void timer3Pwm (){
  Timer3.pwm(getarg(1), getarg(2));
}

void timer3SetPwmDuty (){
  Timer3.setPwmDuty(getarg(1), getarg(2));
}

void timer3DisablePwm (){
  Timer3.disablePwm(getarg(1));
}


