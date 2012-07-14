#define F_CPU 1000000L
#include<avr/io.h>
#include<util/delay.h>
volatile uint8_t led[8][8]={
				   {0,1,2,3,4,5,6,7},
				   {8,9,10,11,12,13,14,15},
				   {16,17,18,19,20,21,22,23},
				   {24,25,26,27,28,29,30,31},
				   {32,33,34,35,36,37,38,39},
				   {40,41,42,43,44,45,46,47},
				   {48,49,50,51,52,53,54,55},
				   {56,57,58,59,60,61,62,63},
				   				   };
volatile uint8_t led1[6]={224,112,56,28,14,7};
void ledon(uint8_t i,uint8_t j)
{
	
	PORTC=led[i][j];
	_delay_ms(50);
	
}
int main()				
{
uint8_t row=4,col=4;
uint8_t portb;
uint8_t i=1,j=-1;
uint8_t k=3;
DDRC =0xff;
DDRB=0Xff;
//for(k=0;k<=6;k++)

DDRD |=_BV(PD0);
while(1){
/*if(k==5)
k=0;*/
ledon(row,col); 
PORTD =0XFF;
_delay_ms(.1);
PORTD =0;
//_delay_ms(50);
PORTB=led1[k];
//k++;
row=row+i;
col=col+j;
ledon(row,col);
if(row==7)              //last row
	{
	//i=-1;
	if(led[row][col]==57)
		{
		portb=PORTB;
			if((portb==224) || (portb==112))
				{
				PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;
			}	}	
//i=-1;
	if(led[row][col]==58)
		{
		portb=PORTB;
			if((portb==224) || (portb==112) || (portb==56))
				{
				PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;
			}	}	
if(led[row][col]==59)
		{
		portb=PORTB;
			if((portb==28) || (portb==112) || (portb==56))
				{
				PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;
			}	}	


if(led[row][col]==60)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==56))
				{
				PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;
			}	}
if(led[row][col]==61)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==7))
				{
				PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;
			}	}	
	
if(led[row][col]==62)
		{
		portb=PORTB;
			if((portb==14) || (portb==7))
				{
				PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;
			}	}	
if(led[row][col]==63)
		{
		portb=PORTB;
			if((portb==7))
				{
				PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;
			}	}		
	
	row=7;

	i=-i;
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/



	}
if(row==0)				//ist row
	{
	row=0;
	i=-i;
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/
	}
if(col==0)
	{
	col=1;
	j=-j;
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/	
	}
if(col==7)
	{
	col=6;
	j=-j;
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/	
	}
k=k+1;
if(k>=6)
k=0;
}
}
