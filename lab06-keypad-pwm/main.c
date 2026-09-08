#include <avr/io.h>
#include <avr/interrupt.h>
#define LEDON PORTB|=(1<<PB5)
#define LEDOFF PORTB&=~(1<<PB5)
int LED_Cycle=0;void keypad_init();void keypad_Timer();void LED_Num(int time_on);
int keypad[4][4]={{1,2,3,0},{4,5,6,0},{7,8,9,0},{0,0,0,0}};
void keypad_init(){DDRD|=(1<<DDD4)|(1<<DDD5)|(1<<DDD6)|(1<<DDD7);PORTD|=(1<<PORTD4)|(1<<PORTD5)|(1<<PORTD6)|(1<<PORTD7);DDRB&=~((1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3));PORTB|=(1<<PORTB0)|(1<<PORTB1)|(1<<PORTB2)|(1<<PORTB3);DDRB|=(1<<DDB5);}
void keypad_Timer(){TCCR0A|=(1<<WGM01);OCR0A=624;TCCR0B|=(1<<CS02);TIMSK0|=(1<<OCIE0A);}
void LED_Num(int time_on){TCCR2A|=(1<<WGM21);OCR2A=124;OCR2B=(OCR2A/10)*time_on;TCCR2B|=(1<<CS22)|(1<<CS21);TIMSK2|=(1<<OCIE2A)|(1<<OCIE2B);}
int main(void){keypad_init();keypad_Timer();sei();while(1){}return 0;}
ISR(TIMER0_COMPA_vect){for(int i=0;i<4;i++){PORTD&=~(1<<(PORTD4+i));for(int j=0;j<4;j++){if(!(PINB&(1<<PINB0+j))){LED_Cycle=keypad[i][j];LED_Num(LED_Cycle);}}PORTD|=(1<<(PORTD4+i));}}
ISR(TIMER2_COMPA_vect){LEDON;}ISR(TIMER2_COMPB_vect){LEDOFF;}
