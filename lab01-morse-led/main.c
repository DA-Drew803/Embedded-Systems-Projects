#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <ctype.h>
void dot(void) {
PORTB |= (1 << PORTB5);//LED on
_delay_ms(200);
PORTB &= ~(1 << PORTB5);//LED off
_delay_ms(200);
}
void dash(void) {
PORTB |= (1 << PORTB5);
_delay_ms(600);
PORTB &= ~(1 << PORTB5);
_delay_ms(200);
}
void letter_space(void) {
_delay_ms(600); // delay between letters
}
void word_space(void) {
_delay_ms(1400); // delay between words
}
void morse(char str) { //links char to morse code
if (str == 'A' || str == 'a')
{ dot(); dash(); }
else if (str == 'B' || str == 'b')
{ dash(); dot(); dot(); dot(); }
else if (str == 'C' || str == 'c')
{ dash(); dot(); dash(); dot(); }
else if (str == 'D' || str == 'd')
{ dash(); dot(); dot(); }
else if (str == 'E' || str == 'e')
{ dot(); }
else if (str == 'F' || str == 'f')
{ dot(); dot(); dash(); dot(); }
else if (str == 'G' || str == 'g')
{ dash(); dash(); dot();}
else if (str == 'H' || str == 'h')
{ dot(); dot(); dot(); dot(); }
else if (str == 'I' || str == 'i')
{ dot(); dot(); }
else if (str == 'J' || str == 'j')
{ dot(); dash(); dash(); dash(); }
else if (str == 'K' || str == 'k')
{ dash(); dot(); dash(); }
else if (str == 'L' || str == 'l')
{ dot(); dash(); dot(); dot(); }
else if (str == 'M' || str == 'm')
{ dash(); dash(); }
else if (str == 'N' || str == 'n')
{ dash(); dot(); }
else if (str == 'O' || str == 'o')
{ dash(); dash(); dash(); }
else if (str == 'P' || str == 'p')
{ dot(); dash(); dash(); dot(); }
else if (str == 'Q' || str == 'q')
{ dash(); dash(); dot(); dash(); }
else if (str == 'R' || str == 'r')
{ dot(); dash(); dot(); }
else if (str == 'S' || str == 's')
{ dot(); dot(); dot(); }
else if (str == 'T' || str == 't')
{ dash(); }
else if (str == 'U' || str == 'u')
{ dot(); dot(); dash(); }
else if (str == 'V' || str == 'v')
{ dot(); dot(); dot(); dash(); }
else if (str == 'W' || str == 'w')
{ dot(); dash(); dash(); }
else if (str == 'X' || str == 'x')
{ dash(); dot(); dot(); dash(); }
else if (str == 'Y' || str == 'y')
{ dash(); dot(); dash(); dash(); }
else if (str == 'Z' || str == 'z')
{ dash(); dash(); dot(); dot(); }
else if (str == '0')
{ dash(); dash(); dash(); dash(); dash(); }
else if (str == '1')
{ dot(); dash(); dash(); dash(); dash(); }
else if (str == '2')
{ dot(); dot(); dash(); dash(); dash(); }
else if (str == '3')
{ dot(); dot(); dot(); dash(); dash(); }
else if (str == '4')
{ dot(); dot(); dot(); dot(); dash(); }
else if (str == '5')
{ dot(); dot(); dot(); dot(); dot(); }
else if (str == '6')
{ dash(); dot(); dot(); dot(); dot(); }
else if (str == '7')
{ dash(); dash(); dot(); dot(); dot(); }
else if (str == '8')
{ dash(); dash(); dash(); dot(); dot(); }
else if (str == '9')
{ dash(); dash(); dash(); dash(); dot(); }
letter_space();
}
void blink_message(const char* msg) { //loops thru each char in string
for (int i = 0; msg[i] != '\0'; i++) {
if (msg[i] == ' ') {//if char is a space
word_space();
} else {
morse(msg[i]);//calls for letters/numbers
}
}
}
int main(void) {
DDRB |= (1 << DDB5); // Set PORTB5 as output
const char* string = "Firstname Lastname 123456789"; // name and RedID
while (1) {
blink_message(string);//blink code
_delay_ms(5000); // Delay before repeating
}
}
