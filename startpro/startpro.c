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
void ledon(uint8_t i,uint8_t j)
{
	
	PORTC=led[i][j];
	_delay_ms(100);
	
}
int main()				
{
uint8_t row=4,col=7;
uint8_t i=1,j=-1;
DDRC =0xff;
while(1){
ledon(row,col); //INTIAL POSTION
_delay_ms(100);
row=row+i;
col=col+j;
ledon(row,col);
if(row==7)              //last row
	{
	//i=-1;
	
	row=7;
	i=-i;
	}
if(row==0)				//ist row
	{
	row=0;
	i=-i;
	}
if(col==0)
	{
	col=1;
	j=-j;	
	}
if(col==7)
	{
	col=6;
	j=-j;	
	}
}
}
