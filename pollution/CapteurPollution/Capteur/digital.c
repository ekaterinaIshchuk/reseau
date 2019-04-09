#include <avr/io.h>

/** Function for the digital I/O  **/

void output_init(void){
DDRB |= 0x1f; // Pins 8 to 12 as output
}

void output_set(int pin,unsigned char value){
if(pin<8 || pin>12) return;
unsigned char mask=(1 << (pin-8));
if(value==0) PORTB &= ~mask ; else PORTB |= mask;
}

void input_init(void){
DDRD &= 0x83;  // Pins 2 to 6 as input
PORTD |= 0x0c; // Pull-up activated on pins 2 and 3
}

unsigned char input_get(int pin){
if(pin<2 || pin>6) return 0xff;
unsigned char mask=(1 << pin);
return ((PIND&mask)!=0)?1:0;
}

