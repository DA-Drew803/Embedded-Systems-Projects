#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <ctype.h>
void dot(void){PORTB|=(1<<PORTB5);_delay_ms(200);PORTB&=~(1<<PORTB5);_delay_ms(200);}
void dash(void){PORTB|=(1<<PORTB5);_delay_ms(600);PORTB&=~(1<<PORTB5);_delay_ms(200);}
void letter_space(void){_delay_ms(600);} void word_space(void){_delay_ms(1400);}
void morse(char s){
 if(s=='A'||s=='a'){dot();dash();}else if(s=='B'||s=='b'){dash();dot();dot();dot();}
 else if(s=='C'||s=='c'){dash();dot();dash();dot();}else if(s=='D'||s=='d'){dash();dot();dot();}
 else if(s=='E'||s=='e'){dot();}else if(s=='F'||s=='f'){dot();dot();dash();dot();}
 else if(s=='G'||s=='g'){dash();dash();dot();}else if(s=='H'||s=='h'){dot();dot();dot();dot();}
 else if(s=='I'||s=='i'){dot();dot();}else if(s=='J'||s=='j'){dot();dash();dash();dash();}
 else if(s=='K'||s=='k'){dash();dot();dash();}else if(s=='L'||s=='l'){dot();dash();dot();dot();}
 else if(s=='M'||s=='m'){dash();dash();}else if(s=='N'||s=='n'){dash();dot();}
 else if(s=='O'||s=='o'){dash();dash();dash();}else if(s=='P'||s=='p'){dot();dash();dash();dot();}
 else if(s=='Q'||s=='q'){dash();dash();dot();dash();}else if(s=='R'||s=='r'){dot();dash();dot();}
 else if(s=='S'||s=='s'){dot();dot();dot();}else if(s=='T'||s=='t'){dash();}
 else if(s=='U'||s=='u'){dot();dot();dash();}else if(s=='V'||s=='v'){dot();dot();dot();dash();}
 else if(s=='W'||s=='w'){dot();dash();dash();}else if(s=='X'||s=='x'){dash();dot();dot();dash();}
 else if(s=='Y'||s=='y'){dash();dot();dash();dash();}else if(s=='Z'||s=='z'){dash();dash();dot();dot();}
 else if(s=='0'){dash();dash();dash();dash();dash();}else if(s=='1'){dot();dash();dash();dash();dash();}
 else if(s=='2'){dot();dot();dash();dash();dash();}else if(s=='3'){dot();dot();dot();dash();dash();}
 else if(s=='4'){dot();dot();dot();dot();dash();}else if(s=='5'){dot();dot();dot();dot();dot();}
 else if(s=='6'){dash();dot();dot();dot();dot();}else if(s=='7'){dash();dash();dot();dot();dot();}
 else if(s=='8'){dash();dash();dash();dot();dot();}else if(s=='9'){dash();dash();dash();dash();dot();}
 letter_space();
}
void blink_message(const char* msg){for(int i=0;msg[i]!='\0';i++){if(msg[i]==' ')word_space();else morse(msg[i]);}}
int main(void){DDRB|=(1<<DDB5);const char* string="YOUR NAME 123456789";while(1){blink_message(string);_delay_ms(5000);}}
