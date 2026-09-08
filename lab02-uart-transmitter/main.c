#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600 // define baud
#define BAUD_RATE ((F_CPU)/(BAUD*16UL)-1) // set baud rate value for UBRR
void uart_init(void); //intialzes UART tool
void uartTran(char data); //transmits one char over UART
int main(void)
{
uart_init(); //intialzes UART
char RedID[] = "123456789\r\n"; // RedID that sends over, r/n to create new lines
while(1)
{
for(int i=0; RedID[i]!='\0'; i++) //loops thru each char, sends using uartTran
{
uartTran(RedID[i]); //sends each char
}
_delay_ms(500); // delay
}
return 0;
}
//initialize UART
void uart_init(void)
{
UBRR0H = (BAUD_RATE>>8); // shift register right by 8 bits
UBRR0L = BAUD_RATE; // set baudrate
UCSR0B |= (1<<TXEN0) | (1<<RXEN0); //makes UART transmitter work
UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00); // 8 bit data format set to 1
}
void uartTran(char data)
{
while(!(UCSR0A & (1<<UDRE0))); // waits while register is free
UDR0 = data; //load data in register
}
