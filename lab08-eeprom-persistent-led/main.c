#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#define LEDON PORTB |= (1<<5)
#define LEDOFF PORTB &= ~(1<<5)
uint8_t EEMEM address = 0; // start at 0
uint8_t duty_cycle; //duty cycle
void timer0_init() { // trigger when LED is off/on
TCCR0A |= (1 << WGM01);//CTC mode
OCR0A = 77;//5ms
OCR0B = 0;
TCCR0B |= (1 << CS02) | (1 << CS00); // CS02 and CS00 together select 1024 prescaler
TIMSK0 |= (1<<OCIE0A) | (1<<OCIE0B);
}
int main(void) {
DDRB |= (1<<DDB5);//PB5 output
timer0_init();
duty_cycle = eeprom_read_byte(&address);// load the last saved duty cycle from EEPRO
if (duty_cycle >= 100) { // Check if the duty cycle has reached/passed 100
duty_cycle = 0; // if pass 100 loop back to 0
} else {
duty_cycle = duty_cycle + 10; // otherwise increase by 10
}
eeprom_update_byte(&address, duty_cycle);//updates to new value
OCR0B = OCR0A * (duty_cycle / 101.00);//101 because OCROA+1
sei();
while (1) {
}
return 0;
}
ISR (TIMER0_COMPA_vect) {// starts new PWM cycle
LEDON; // Turn the LED on
}
ISR (TIMER0_COMPB_vect) {//when it should turn off
LEDOFF; // Turn the LED off
}
