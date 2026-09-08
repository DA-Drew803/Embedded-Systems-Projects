#include <avr/io.h>
#include <avr/interrupt.h>
#define LEDON PORTB |= (1<<PB5)
#define LEDOFF PORTB &= ~(1<<PB5)
int LED_Cycle = 0; // duty cycle
void keypad_init();
void keypad_Timer();
void LED_Num(int time_on);
void keypad_init() {
DDRD |= (1<<DDRD4) | (1<<DDRD5) | (1<<DDRD6) | (1<<DDRD7); //high
PORTD |= (1<<PORTD4) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7);
DDRB &= ~((1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3));
PORTB |= (1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3);//columns
DDRB |= (1<<DDB5);// pull up
}
int keypad[4][4] = {
{1,2,3,0},
{4,5,6,0},
{7,8,9,0},
{0,0,0,0}
};
void keypad_Timer() {
TCCR0A |= (1 << WGM01); // ctc mode
//RedID = 123456789, changed for privacy but my x was 9
// x = 9, -> (x = 9+1) = 10ms
//FCPU = 16MHz, prescaler = 256, timer frequency = 16MHz / 256 = 62500 Hz, 10ms = 0.010s
// OCR0A = (62500 * 0.010) - 1 = 625 - 1 = 624
OCR0A = 624;
TCCR0B |= (1 << CS02); // presclaer
TIMSK0 |= (1 << OCIE0A);// enable interrupt
}
void LED_Num( int time_on) {
TCCR2A |= (1 << WGM21);
// z = 4, so (4+1)*100 Hz = 500 Hz,FCPU = 16MHz, prescaler = 256, timer frequency =
16MHz / 256 = 62500 Hz
// OCR2A = (62500 / 500) - 1 = 125 - 1 = 124
OCR2A = 124;
OCR2B = (OCR2A / 10) * time_on; //button 10% increase per cycle
TCCR2B |= (1 << CS22) | (1 << CS21);
TIMSK2 |= (1 << OCIE2A) | (1 << OCIE2B); // enable interrupts
}
int main(void) {
keypad_init();
keypad_Timer();
sei();// enable interupps
while (1) {// does nothing but needed to keep the code from stopping
}
return 0;
}
ISR (TIMER0_COMPA_vect) { //read button press and updates cycle
for (int i = 0; i < 4; i++) {
PORTD &= ~(1<<(PORTD4 + i));
for (int j = 0; j < 4; j++) {
if (!(PINB & (1 << PINB0 + j))) {// check if button is pressed
LED_Cycle = keypad[i][j];// get 0-9
LED_Num(LED_Cycle); //update duty cycle
}
}
PORTD |= (1<<(PORTD4 + i)); // set row high
}
}
ISR (TIMER2_COMPA_vect) {
LEDON; // Turn the LED ON
}
ISR (TIMER2_COMPB_vect) {
LEDOFF; // Turn the LED OFF
}
