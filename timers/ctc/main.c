#include <avr/io.h>
//#include <stdio.h>

/*
This example shows how to use CTC output on Timer 0
Assuming the main oscillator is 8Mhz, the prescaler for our clock divides
this by 1024 giving a tick period of 128us

Setting OCR0A to 255 with a tick period of 128us gives us a delay of 32640us
so approx 33ms. If you connect a logic analyzer on OCR0A you should see approx
33ms square wave
*/

int main() {
  DDRD |= _BV(PD6); // PD6 / OC0A set as an output

  OCR0A  = 255;                       // Compare value, OC0A is toggled when OCR0A and TCNT0 match
  TCCR0A |= _BV(COM0A0) | _BV(WGM01); // Toggle OC0A on match
  TCCR0B |= _BV(CS00) | _BV(CS02);    // Set Prescaler to /1024 also starts the timer

  while(1) {
    // main loop
  }
}
