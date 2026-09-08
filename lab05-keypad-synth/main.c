#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void key_init(void){DDRD|=(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7);DDRB&=~((1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3));PORTB|=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);DDRD|=(1<<PD1);}
void timer_init(uint8_t time_val){TCCR0A=(1<<WGM01);TCCR0B=(1<<CS01);OCR0A=time_val;TCNT0=0;}
void key_note(uint8_t freq){timer_init(freq);while(1){while((TIFR0&(1<<OCF0A))==0);PORTD^=(1<<PD1);TIFR0|=(1<<OCF0A);if((PINB&(1<<PB0))&&(PINB&(1<<PB1))&&(PINB&(1<<PB2))&&(PINB&(1<<PB3)))break;}}
const uint8_t keypad[4][4]={{227,214,202,191},{180,170,160,151},{143,135,127,120},{113,107,101,95}};
int main(void){key_init();while(1){for(int row=0;row<4;row++){PORTD|=(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7);PORTD&=~(1<<(PD4+row));_delay_us(5);for(int col=0;col<4;col++){if(!(PINB&(1<<col)))key_note(keypad[row][col]);}}}}
