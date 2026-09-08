#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#define LEDON PORTB|=(1<<5)
#define LEDOFF PORTB&=~(1<<5)
uint8_t EEMEM address=0;uint8_t duty_cycle;
void timer0_init(){TCCR0A|=(1<<WGM01);OCR0A=77;OCR0B=0;TCCR0B|=(1<<CS02)|(1<<CS00);TIMSK0|=(1<<OCIE0A)|(1<<OCIE0B);}
int main(void){DDRB|=(1<<DDB5);timer0_init();duty_cycle=eeprom_read_byte(&address);if(duty_cycle>=100)duty_cycle=0;else duty_cycle=duty_cycle+10;eeprom_update_byte(&address,duty_cycle);OCR0B=OCR0A*(duty_cycle/101.00);sei();while(1){}return 0;}
ISR(TIMER0_COMPA_vect){LEDON;}ISR(TIMER0_COMPB_vect){LEDOFF;}
