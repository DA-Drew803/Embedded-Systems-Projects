#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600
#define BAUD_RATE ((F_CPU)/(BAUD*16UL)-1)
void uart_init(void);void uartTran(char);
int main(void){uart_init();DDRD|=(1<<DDD4)|(1<<DDD5)|(1<<DDD6)|(1<<DDD7);DDRB&=~((1<<DDB0)|(1<<DDB1)|(1<<DDB2)|(1<<DDB3));PORTB|=(1<<PORTB0)|(1<<PORTB1)|(1<<PORTB2)|(1<<PORTB3);PORTD|=(1<<4|1<<5|1<<6|1<<7);const char button[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};while(1){for(int i=4;i<8;i++){PORTD&=~(1<<i);for(int j=0;j<4;j++){if(!(PINB&(1<<j))){uartTran(button[i-4][j]);_delay_ms(500);}}PORTD|=(1<<i);}}}
void uart_init(void){UBRR0H=(BAUD_RATE>>8);UBRR0L=BAUD_RATE;UCSR0B|=(1<<TXEN0)|(1<<RXEN0);UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);}
void uartTran(char letter){while(!(UCSR0A&(1<<UDRE0)));UDR0=letter;}
