#define F_CPU 1000000L
#include<avr/io.h>
#include<util/delay.h>
volatile uint8_t ledmat[8][8]={
						{0,1,2,3,4,5,6,7},
						{8,9,10,11,12,13,14,15},
						{16,17,18,19,20,21,22,23},
						{24,25,26,27,28,29,30,31},
						{32,33,34,35,36,37,38,39},
						{40,41,42,43,44,45,46,47},
						{48,49,50,51,52,53,54,55},
						{56,57,58,59,60,61,62,63}
						};

void ledon(uint8_t i,uint8_t j)
{
	//DDRC=63;
	DDRC=0XFF;
	PORTC=ledmat[i][j];
	_delay_ms(70);
	
}
int main()
{
	
	uint8_t k=0;uint8_t l=0;
	while(1){
	for(l=0;l<=8;l++)
		for(k=0;k<=8;k++)
		  ledon(l,k);
		
}
}

