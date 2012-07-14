#define F_CPU 4000000L
#include<avr/io.h>
#include<avr/delay.h>
int main()
{

DDRC=0XFF;
while(1)
{
PORTC=0;
PORTC=1;
PORTC=6;
PORTC=7;
PORTC=8;
PORTC=9;
PORTC=14;
PORTC=15;
PORTC=27;
PORTC=28;
PORTC=35;
PORTC=36;
PORTC=49;
PORTC=54;
PORTC=58;
PORTC=59;
PORTC=60;
PORTC=61;
}}
