#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void key_init(void) {
DDRD |= (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7); //Sets PD4, PD5, PD6, and PD7 as outputs,row
DDRB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3));//: Sets pins PB0, PB1, PB2, and PB3 as inputs,colmn
PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3);//Enables the internal pull up for PB0, PB1, PB2, and PB3
DDRD |= (1 << PD1); // Sets PD1 on as an output for sound
}
// Timer/Counter
void timer_init(uint8_t time_val) {
TCCR0A = (1 << WGM01); // Sets Timer/Counter to CTC
TCCR0B = (1 << CS01); //Sets the prescaler for Timer/Counter to 8
OCR0A = time_val;
TCNT0 = 0; //restets register
}
void key_note(uint8_t freq) {
timer_init(freq); //infinite loop to generate the tone/freq
while (1) {
while ((TIFR0 & (1 << OCF0A)) == 0); //wait till OCF0A flag is set
PORTD ^= (1 << PD1); // Toggle PD1
TIFR0 |= (1 << OCF0A); // Clear flag
if ((PINB & (1 << PB0)) && (PINB & (1 << PB1)) && (PINB & (1 << PB2)) && (PINB & (1 << PB3))) { //check if all column are High
break; //stop tone when button released
}
}
}
const uint8_t keypad[4][4] = {{227, 214, 202, 191}, {180, 170, 160, 151}, {143, 135, 127, 120}, {113, 107, 101, 95}}; //math 440* 2^(1/12) ,x = keypad num
int main(void) {
key_init();
while (1) {
for (int row = 0; row < 4; row++) { // loops thru keypad row
PORTD |= (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7);//Sets PD4
to PD7 high as default
PORTD &= ~(1 << (PD4 + row));//Pulls the current row low
_delay_us(5); //
for (int col = 0; col < 4; col++) {//loops thru keypad column
if (!(PINB & (1 << col))) { // Checks if the current column pin is low. if low = button press
key_note(keypad[row][col]); //calls key_note with the
correct tone
}
}
}
}
}
