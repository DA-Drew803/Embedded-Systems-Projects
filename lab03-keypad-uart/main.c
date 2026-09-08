#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600 
#define BAUD_RATE ((F_CPU)/(BAUD*16UL)-1)  
void uart_init(void); //intialzes UART tool
void uartTran(char); //transmits one char over UART
int main(void)
{
uart_init(); //intialzes UART
DDRD |= (1<<DDD4) | (1 << DDD5) | (1<<DDD6) | (1<<DDD7) ; //sets pd4-pd7 row pins of keypad as output
DDRB &= ~((1<< DDB0) | (1<< DDB1) | (1<< DDB2) | (1<< DDB3)); //sets pb0-pb3 column rows of keypads as inputs
PORTB |= (1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3) ; //enables pull up, makes default input as high to make key press as low
PORTD |= (1<<4|1<<5 | 1<<6| 1<<7); // set all row pins to high
const char button [4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}}; // 2d array for trans
while(1){
for(int i = 4; i<8; i++) // looks thru pd4-pd7
{
PORTD &= ~(1<<i); // sets one row low to check for key presses on that row
for (int j = 0; j<4; j++) // lopps thru column pins pb0 to pb3 to see if button is pressed
{
if (!(PINB & (1 << j))) //check if any column pin if pulled low, which means checks for key press
{
uartTran(button[i - 4][j]);//Sends the correct character from the button array from UART. -4 used to map correctly
_delay_ms(500); //Adds a delay to avoid multiple reads from a single press
}
}
PORTD |= (1 << i);// Sets the row pin back to high before moving to the next row, makes sure only one row is active at a time.
}
}
}
//initialize UART
void uart_init(void)
{
UBRR0H = (BAUD_RATE>>8); // shift register right by 8 bits
UBRR0L = BAUD_RATE; // set baudrate
UCSR0B |= (1<<TXEN0) | (1<<RXEN0); //makes UART transmitter work
UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00); // 8 bit data format set to 1
}
void uartTran(char letter)
{
while(!(UCSR0A & (1<<UDRE0))); // waits while register is free
UDR0 = letter; //load data in register
}
