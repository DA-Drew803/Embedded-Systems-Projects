#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600
#define BAUD_RATE ((F_CPU)/(BAUD*16UL)-1)
void uart_init(void);void uartTran(char data);
int main(void){uart_init();char RedID[]="123456789\r\n";while(1){for(int i=0;RedID[i]!='\0';i++)uartTran(RedID[i]);_delay_ms(500);}return 0;}
void uart_init(void){UBRR0H=(BAUD_RATE>>8);UBRR0L=BAUD_RATE;UCSR0B|=(1<<TXEN0)|(1<<RXEN0);UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);}
void uartTran(char data){while(!(UCSR0A&(1<<UDRE0)));UDR0=data;}
