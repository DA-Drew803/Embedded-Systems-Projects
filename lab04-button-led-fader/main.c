#include <avr/io.h>
#define F_CPU 16000000UL
#define LedOn PORTB |= (1<<5) //sets bit 5 high
#define LedOff PORTB &= ~(1<<5) //clears bit 5
int main(void)
{
TCCR0A |= (1 << WGM01); //ctc mode
TCCR0B |= (1 << CS02) | (1 << CS00); // Set prescaler to 1024
DDRB &= ~(1 << DDB7); // Set PB7 as input
DDRB |= (1 << DDB5); // Set PB5 as output
PORTB |= (1 << PORTB7); // Enable pull-up resistor on PB7
OCR0A = 155; // top value
OCR0B = 0x00; // timing led on duration, default off
while (1)
{
if (!(PINB & (1 << 7)) && (OCR0B < OCR0A)) {
OCR0B++; //if pb7==0 and duty cycle not maxed, lled gets brighter
}
LedOn; // Turn LED ON during duty cycle (OCR0B ticks)
while ((TIFR0 & (1 << OCF0B)) == 0) {}
TIFR0 |= (1 << OCF0B); //clears ocfob
if ((PINB & (1 << 7)) && (OCR0B > 0)) {
OCR0B--;// if botton not pressed, and >0, reduce brightness gradually
}
LedOff; // Turn LED OFF for the rest of the period
while ((TIFR0 & (1 << OCF0A)) == 0) {}
TIFR0 |= (1 << OCF0A); //clears ocfoa
}
}
