#include <avr/io.h>
#include <avr/interrupt.h>
#define LEDON PORTB|=(1<<5)
#define LEDOFF PORTB&=~(1<<5)
void timer0_init();void timer2_init(uint16_t ADC_value);void adc_init();
void adc_init(void){ADMUX=(1<<REFS0)|(1<<MUX1)|(1<<MUX0);DDRB|=(1<<DDB5);DDRC&=~(1<<PINC3);ADCSRA=(1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);}
void timer0_init(void){TCCR0A|=(1<<WGM01);OCR0A=624;TCCR0B|=(1<<CS02);TIMSK0|=(1<<OCIE0A);}
void timer2_init(uint16_t ADC_value){TCCR2A|=(1<<WGM21);OCR2A=124;OCR2B=(uint8_t)(OCR2A*(ADC_value/1024.0));TCCR2B|=(1<<CS22)|(1<<CS21);TIMSK2|=(1<<OCIE2A)|(1<<OCIE2B);}
ISR(TIMER0_COMPA_vect){ADCSRA|=(1<<ADSC);}ISR(ADC_vect){uint16_t ADC_result=ADC;timer2_init(ADC_result);}ISR(TIMER2_COMPA_vect){LEDON;}ISR(TIMER2_COMPB_vect){LEDOFF;}
int main(void){timer0_init();adc_init();sei();while(1){}}
