#include <avr/io.h>
#define F_CPU 16000000UL
#define LedOn PORTB|=(1<<5)
#define LedOff PORTB&=~(1<<5)
int main(void){TCCR0A|=(1<<WGM01);TCCR0B|=(1<<CS02)|(1<<CS00);DDRB&=~(1<<DDB7);DDRB|=(1<<DDB5);PORTB|=(1<<PORTB7);OCR0A=155;OCR0B=0x00;while(1){if(!(PINB&(1<<7))&&(OCR0B<OCR0A))OCR0B++;LedOn;while((TIFR0&(1<<OCF0B))==0){}TIFR0|=(1<<OCF0B);if((PINB&(1<<7))&&(OCR0B>0))OCR0B--;LedOff;while((TIFR0&(1<<OCF0A))==0){}TIFR0|=(1<<OCF0A);}}
