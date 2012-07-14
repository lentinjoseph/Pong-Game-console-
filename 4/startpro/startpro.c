#define F_CPU 1000000L
#include<avr/io.h>
#include<util/delay.h>
//8x8 led matrix values//
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
//paddle values//
volatile uint8_t led1[6]={224,112,56,28,14,7};
//led pixel activator//
void ledon(uint8_t i,uint8_t j)
{
	
	PORTC=led[i][j];
	_delay_ms(100);		//time of led activate on pong board
	
}
//when reset done clear screen//
void reset(uint8_t i,uint8_t j)
{
	DDRD=0Xff;			//for buzzer//
	PORTD=0X00;
	_delay_ms(100);
	PORTD=0XFF;
	DDRD=0X00;
	
	for(i=0;i<8;i++){		//for clearing screen//
		for(j=0;j<8;j++){
	PORTC=led[i][j];
	_delay_ms(5);
	}
	}

	
}
int main()				
{
while(1)
{

//initial row and column//
uint8_t row=4,col=7; 

//for reading paddle value//

uint8_t portb;

//for acessing led matrix//
uint8_t i=1,j=-1;

DDRC =0xff; 	//for led matrix input//
DDRB=0Xff;		//for pad//
volatile uint8_t m=2;	
DDRD=0x00; 			//for input key//
PORTB=0XFF;
_delay_ms(100);
PORTB=led1[2]; //initial pad position//

PORTD=0xFF;  // Internal pullup is enable 

//activate each led
ledon(row,col);


_delay_ms(100);
while(1){
  
//acessing each led
ledon(row,col); 

//row and colomn algorithm
row=row+i;
col=col+j;
ledon(row,col);


if(row==7)              //last row condition
	{
	
	if(led[row][col]==56)
	{
		portb=PORTB;
			if((portb==224))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			}
			}
	if(led[row][col]==57)
		{
		portb=PORTB;
			if((portb==224) || (portb==112))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			}
			}	
//i=-1;
	if(led[row][col]==58)
		{
		portb=PORTB;
			if((portb==224) || (portb==112) || (portb==56))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			}	}
if(led[row][col]==59)
		{
		portb=PORTB;
			if((portb==28) || (portb==112) || (portb==56))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			
			}	
}

if(led[row][col]==60)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==56))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			
			}}
if(led[row][col]==61)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==7))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}
			else{
		
					reset(i,j);
				
							
				break;
			
				}	
	}
if(led[row][col]==62)
		{
		portb=PORTB;
			if((portb==14) || (portb==7))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			
			}}	
if(led[row][col]==63)
		{
		portb=PORTB;
			if((portb==7))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
						}}		
	
	row=7;

	i=-i;
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/



	}
if(row==0)				//1st row condition
	{
	
	if(led[row][col]==0)
	{
		portb=PORTB;
			if((portb==224))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			}
			}
	if(led[row][col]==1)
		{
		portb=PORTB;
			if((portb==224) || (portb==112))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			}
			}	

	if(led[row][col]==2)
		{
		portb=PORTB;
			if((portb==224) || (portb==112) || (portb==56))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			}	}
if(led[row][col]==3)
		{
		portb=PORTB;
			if((portb==28) || (portb==112) || (portb==56))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			
			}	
}

if(led[row][col]==4)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==56))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			
			}}
if(led[row][col]==5)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==7))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}
			else{
		
					reset(i,j);
				
							
				break;
			
				}	
	}
if(led[row][col]==6)
		{
		portb=PORTB;
			if((portb==14) || (portb==7))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
			
			}}	
if(led[row][col]==7)
		{
		portb=PORTB;
			if((portb==7))
				{
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
		
					reset(i,j);
				
							
				break;
						}}		
	
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/



	
	row=0;
	i=-i;
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/
	}
if(col==0)			//left side column
	{
	col=1;
	j=-j;
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/	
	}
if(col==7)		//right side column
	{
	col=6;
	j=-j;
	/*PORTD =0XFF;
	_delay_ms(5);
	PORTD =0;*/	
	}
if(!(PIND & 0x01))  // check whether the switch is pressed or not

{
_delay_ms(1);
//while(!(PIND & 0x01)); //wait for debounce

if(!(PIND & 0x01))
{

m++;
PORTB=led1[m];
if(m>=5)
m=4;
//_delay_ms(1);   // On for a half second

} 
}
if(!(PIND & 0x02))  // check whether the switch is pressed or not

{
_delay_ms(1);
if(!(PIND & 0x02))
{
//while(!(PIND & 0x02)); //wait for debounce


m--;
PORTB=led1[m];

if(m<=0)
m=1;


//_delay_ms(1);   // On for a half second

}
} 
}

}}

