#define F_CPU 1000000L
#include<avr/delay.h>
#include<avr/io.h>
volatile uint8_t led[7]={192,96,48,24,12,6,3};
int main(void)

{

volatile uint8_t i=3;
DDRD=0xFC;   // PORTD_0 declared as input

DDRA=0xFF; //PORTA is declared as output
PORTA=0XFF;
_delay_ms(6000);
PORTA=0x00; // initially LED off

PORTD=0xFF;  // Internal pullup is enabled
PORTA=led[3];
while(1==1)  // infinite loop

{

if(!(PIND & 0x01))  // check whether the switch is pressed or not

{

while(!(PIND & 0x01)); //wait for debounce

//PORTA=(1<<1);    // LED on


i++;
PORTA=led[i];
if(i==6)
i=5;
_delay_ms(100);   // On for a half second

//PORTA=0x00;    // LED turns off
}  // if ends here
if(!(PIND & 0x02))  // check whether the switch is pressed or not

{

while(!(PIND & 0x02)); //wait for debounce

//PORTA=(1<<0);    // LED on

i--;
PORTA=led[i];
if(i==0)
i=1;


_delay_ms(100);   // On for a half second

//PORTA=0x00;    // LED turns off

}  // if ends here
}  // while(1 ) ends here

return 0;

} // main ends here

