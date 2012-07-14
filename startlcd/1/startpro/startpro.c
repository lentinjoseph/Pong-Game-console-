#define F_CPU 1000000L
#include<avr/io.h>
#include<util/delay.h>
//8x8 led matrix values//
volatile uint8_t score=0,level=0;
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
volatile uint8_t delay;
uint8_t delay1(uint8_t level){
	if(level==0)delay=250;
	if(level==1)delay=225;
	if(level==2)delay=200;
	if(level==3)delay=175;
	if(level==4)delay=150;
	if(level==5)delay=125;
	if(level==6)delay=100;
	if(level==7)delay=75;
	if(level==8)delay=60;
	if(level==9)delay=40;
	return (delay);} 
//uint8_t n=5;
//uint8_t l=1;
//led pixel activator//
void ledon(uint8_t i,uint8_t j)
{
/*	if(level==0)delay=100;
	if(level==1)delay=50;
	if(level==2)delay=45;
	if(level==3)delay=85;
	if(level==4)delay=80;
	if(level==5)delay=75;
	if(level==6)delay=70;
	if(level==7)delay=65;
	if(level==8)delay=60;
	if(level==9)delay=50;*/
	PORTC=led[i][j];
	
	_delay_ms(delay1(level));
	//n++;
	//if(n>170){
		//n=170;			//time of led activate on pong board
	//	l++;
	//	if(l==2)
		//	n=5;
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
//This function is used to initialize the USART
//at a given UBRR value
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
	/*while(!(UCSRA & (1<<RXC)))
	{
		//Do nothing
	}*/

	//Now USART has got data from host
	//and is available is buffer

	return UDR;
}


//This fuction writes the given "data" to
//the USART which then transmit it via TX line
void USARTWriteNo(uint8_t data)
{
	//Wait untill the transmitter is ready
	while(!(UCSRA & (1<<UDRE)))
	{
		//Do nothing
	}

	//Now write the data to USART buffer

	UDR=data;
}
void USARTWriteChar(unsigned char data)
{
	//Wait untill the transmitter is ready
	while(!(UCSRA & (1<<UDRE)))
	{
		//Do nothing
	}

	//Now write the data to USART buffer

	UDR=data;
}
int main()
{

DDRC =0xff; 	//for led matrix input//
USARTInit(2);	
DDRD=0x00; 			//for input key//
PORTD=0xFF;  // Internal pullup is enable
//unsigned char i;

while(1)		//pong
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
//PORTC=57;
PORTC=58;
PORTC=59;
PORTC=60;
PORTC=61;
//PORTC=62;
if(USARTReadChar()=='a')
break;
/*if(!(PIND & 0x01))  // check whether the switch is pressed or not
{
while(!(PIND & 0x01)); //wait for debounce
break;*/

}


while(1)
{
//initial row and column//
uint8_t row=4,col=7; 
//uint8_t level=0;
//for reading paddle value//

uint8_t portb;

//for acessing led matrix//
uint8_t i=1,j=-1;


DDRB=0Xff;		//for pad//
volatile uint8_t m=2;	

PORTB=0XFF;
_delay_ms(100);
PORTB=led1[2]; //initial pad position//

 

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
			score++;
			//USARTWriteNo(2);

			}	
			else{
					score--;
					//USARTWriteNo(2);
					reset(i,j);
				
							
				break;
			}
			}
	if(led[row][col]==57)
		{
		portb=PORTB;
			if((portb==224) || (portb==112))
				{
					score++;
					//USARTWriteNo(2);

			}	
			else{
					score--;
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
				score++;
				//USARTWriteNo(2);
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			}	}
if(led[row][col]==59)
		{
		portb=PORTB;
			if((portb==28) || (portb==112) || (portb==56))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			
			}	
}

if(led[row][col]==60)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==56))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			
			}}
if(led[row][col]==61)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==7))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}
			else{
					score--;
					reset(i,j);
				
							
				break;
			
				}	
	}
if(led[row][col]==62)
		{
		portb=PORTB;
			if((portb==14) || (portb==7))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			
			}}	
if(led[row][col]==63)
		{
		portb=PORTB;
			if((portb==7))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
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
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			}
			}
	if(led[row][col]==1)
		{
		portb=PORTB;
			if((portb==224) || (portb==112))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
						score--;
						reset(i,j);
				
							
				break;
			}
			}	

	if(led[row][col]==2)
		{
		portb=PORTB;
			if((portb==224) || (portb==112) || (portb==56))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			}	}
if(led[row][col]==3)
		{
		portb=PORTB;
			if((portb==28) || (portb==112) || (portb==56))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			
			}	
}

if(led[row][col]==4)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==56))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			
			}}
if(led[row][col]==5)
		{
		portb=PORTB;
			if((portb==28) || (portb==14) || (portb==7))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}
			else{
					score--;
					reset(i,j);
				
							
				break;
			
				}	
	}
if(led[row][col]==6)
		{
		portb=PORTB;
			if((portb==14) || (portb==7))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
					reset(i,j);
				
							
				break;
			
			}}	
if(led[row][col]==7)
		{
		portb=PORTB;
			if((portb==7))
				{
				score++;
				/*PORTD =0XFF;
				_delay_ms(10);
				PORTD =0;*/
			}	
			else{
					score--;
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
	/*if(USARTReadChar()=='w'){
		_delay_ms(1000);
			reset(i,j);
			}*/
	if (score==9 && level==2)
		USARTWriteChar('W');
	if(score==9){
	level=level+1;

	score=0;}
	
	USARTWriteChar('s');
	USARTWriteNo(score);
	USARTWriteChar('l');
	USARTWriteNo(level);
if(!(PIND & 0x08))  // check whether the switch is pressed or not

{
_delay_ms(1);
//while(!(PIND & 0x01)); //wait for debounce

if(!(PIND & 0x08))
{

m++;
PORTB=led1[m];
if(m>=5)
m=4;
//_delay_ms(1);   // On for a half second

} 
}
if(!(PIND & 0x10))  // check whether the switch is pressed or not

{
_delay_ms(1);
if(!(PIND & 0x10))
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

}


}



