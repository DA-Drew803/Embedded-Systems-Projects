/*
RedID 123456789
X = 9, Y = 9, & Z = 4, REDID changed for privacy but the X,Y,Z are my actual ones used, use last 3 digits for x,Y,Z, ex X=7,Y=8,Z=9
Timer0 = (9+1) = 10ms for OCR0A
Duty cycle frequency = (4+1) * 100 Hz = 500Hz for OCR2A
Y mod 6 = 3
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#define LEDON PORTB |= (1<<5) //LED ON
#define LEDOFF PORTB &= ~(1<<5) //LED OFF
void timer0_init();
void timer2_init(uint16_t ADC_value);
void adc_init();
void adc_init(void)
{
ADMUX = (1 << REFS0) | (1 << MUX1) | (1 << MUX0); // VCC voltage refernce
// ADC3 is on PC3.
DDRB |= (1<<DDB5); //Set LED as output (PB5)
DDRC &= ~(1 << PINC3); //Setting input at PORTC pin 3 for ADC3
ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
//Enabling ADC
}
void timer0_init(void) // interrupt for ADC every 10ms
{
TCCR0A |= (1 << WGM01); //CTC mode
OCR0A = 624; // (625-1)
TCCR0B |= (1 << CS02); //Pre-scaler = 256
TIMSK0 |= (1 << OCIE0A); //Enabling Interrupt for timer0
}
void timer2_init(uint16_t ADC_value)// sets the Led brughtness
{
TCCR2A |= (1 << WGM21); //CTC mode
OCR2A = 124; //(125-1)
OCR2B = (uint8_t)(OCR2A * (ADC_value / 1024.0)); //max bit ADC value, makes ADC
0-1 range,ADC value controls brightness
TCCR2B |= (1 << CS22) | (1 << CS21); //Pre-scaler = 256
TIMSK2 |= (1 << OCIE2A) | (1 << OCIE2B); //Enabling Interrupts
}
ISR(TIMER0_COMPA_vect)
{
ADCSRA |= (1 << ADSC); // start ADC conversion manually
}
ISR(ADC_vect)
{
uint16_t ADC_result = ADC; //save result to variable
timer2_init(ADC_result); // update based on new ADC value
}
ISR(TIMER2_COMPA_vect)
{
LEDON; // Turn LED on at start of PWM cycle
}
ISR(TIMER2_COMPB_vect)
{
LEDOFF; // Turn LED off at OCR2B match to control duty cycle
}
int main(void)
{
timer0_init();
adc_init();
sei(); //Enable global interrupt
while (1)
{
}
}
