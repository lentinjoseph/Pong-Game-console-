// Program to control lcd and score





#define F_CPU 1000000L

#include <avr/io.h>
#include<util/delay.h>
#include <inttypes.h>
#include<avr/interrupt.h>
#include "lcd.h"
uint8_t i=0,j=0,score=0,level=0,end=0,pong=10;
uint8_t scoreone[10]={32,33,34,35,36,37,38,39,40,41};
uint8_t scoretwo[10]={16,17,18,19,20,21,22,23,24,25};
unsigned char sco;

/*void score1(uint8_t score)
{
PORTC=scoreone[score];
}
void score2(uint8_t score)
{
PORTC=scoretwo[score];
}*/
//This function is used to initialize the USART
//at a given UBRR value

/*ISR(USART_RXC_vect)
	{
	if('W'==UDR);{
		LCDClear();
		LCDWriteStringXY(0,0,"***YOU  WIN***");
		LCDWriteStringXY(0,1,"Congrats.. :-)");
		}
		}*/


void USARTInit(uint16_t ubrr_value)
{

   //Set Baud rate
   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);

   /*Set Frame Format


   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit
   >> char size 8

   */

   UCSRC=(1<<URSEL)|(3<<UCSZ0);


   //Enable The receiver and transmitter
   UCSRB=(1<<RXEN)|(1<<TXEN);


}


//This function is used to read the available data
//from USART. This function will wait untill data is
//available.
uint8_t USARTReadChar()
{
	//Wait untill a data is available
	while(!(UCSRA & (1<<RXC)))
	{
		//Do nothing
	}

	//Now USART has got data from host
	//and is available is buffer

	return UDR;
}


//This fuction writes the given "data" to
//the USART which then transmit it via TX line
void USARTWritechar(unsigned char data)
{
	//Wait untill the transmitter is ready
	while(!(UCSRA & (1<<UDRE)))
	{
		//Do nothing
	}

	//Now write the data to USART buffer

	UDR=data;
}
uint8_t USARTReadNo()
{
	//Wait untill a data is available
	while(!(UCSRA & (1<<RXC)))
	{
		//Do nothing
	}

	//Now USART has got data from host
	//and is available is buffer

	return UDR;
}

int main()
{
	//unsigned char sco;
	//uint8_t i=0,j=0,score=0,level=0;
	//This DEMO program will demonstrate the use of simple
	//function for using the USART for data communication
	//sei();
	
	//for Baud rate = 19200bps
	//UBRR value = 51



	USARTInit(2);		//UBRR = 2
	//unsigned char i;

	//Initialize LCD module
	InitLCD(0);

	//Clear the screen
	LCDClear();
	/*ISR(USART_RXC_vect)
	{
	if('W'==UDR);{
		LCDClear();
		LCDWriteStringXY(0,0,"***YOU  WIN***");
		LCDWriteStringXY(0,1,"Congrats.. :-)");
		}
		}*/
	//Simple string printing
	LCDWriteStringXY(2,0,"Welcome");
	LCDWriteStringXY(10,0,"To");
	_delay_ms(2000);
	LCDClear();
	LCDWriteStringXY(2,0,"Pong Gaming")
	LCDWriteStringXY(4,2,"Console");
	_delay_ms(3000);
	LCDClear();
	//A string on line 2
	LCDWriteStringXY(4,0,"Loading ");

//Print some numbers
	for (i=0;i<=100;i+=1)
	{
		LCDWriteIntXY(13,1,i,2);
		LCDWriteStringXY(15,1,"%");
		_delay_ms(50);
		if(i%10==0)
		LCDWriteStringXY(j++,1,"|");	


	}

	//Clear the screen
	LCDClear();

	_delay_ms(1000);

	LCDWriteStringXY(3,0,"Lets");
	LCDWriteStringXY(8,1,"Play");
	_delay_ms(1000);
	USARTWritechar('a');
	_delay_ms(100);
	LCDClear();
	/*LCDWriteString("SCORE:");
	LCDWriteStringXY(0,1,"LEVEL:");
	LCDWriteStringXY(9,0,"PONG:");*/
	while(1){

	sco=USARTReadChar();
	
	 if(sco=='s')
	 		
		score=USARTReadNo();
			
	 if(sco=='l')
		level=USARTReadNo();
	if(sco=='g')
		pong=USARTReadNo();

	if(sco=='w')
		{

		end=USARTReadNo();
		if(end==3)
			{
		LCDClear();
		LCDWriteStringXY(0,0,"***YOU  WIN***");
		LCDWriteStringXY(0,1,"Congrats.. :-)");
		break;
			}
		}
if(sco=='o')
		{

		end=USARTReadNo();
		if(end==4)
			{
		LCDClear();
		LCDWriteStringXY(4,0,"YOU  LOSE");
		LCDWriteStringXY(2,1,"FOOL.. :-(");
		break;
			}
		}
	/*if(score==9){
		LCDClear();
		LCDWriteStringXY(2,0,"You");
		LCDWriteStringXY(4,1,"Win");
		LCDWriteIntXY(7,1,level,1);
		_delay_ms(1000);
		LCDClear();
		}*/
	LCDClear();
	LCDWriteString("SCORE:");
	LCDWriteStringXY(4,1,"LEVEL:");
	LCDWriteStringXY(9,0,"PONG:");
	LCDWriteIntXY(6,0,score,1);
	LCDWriteIntXY(10,1,level,1);
	LCDWriteIntXY(15,0,pong,1);
	
	/*ISR(USART_RXC_vect)
	{
	if('W'==UDR);
		LCDClear();
		LCDWriteStringXY(0,0,"***YOU  WIN***");
		LCDWriteStringXY(0,1,"Congrats.. :-)");
	}*/
	}
}
		

