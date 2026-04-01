#include<LPC21XX.H>
#include "delay_header.h"
#define LCD_D 0xf<<14
#define RS 1<<18
#define E 1<<19

void LCD_COMMAND(unsigned char );
void LCD_DATA(unsigned char );
void LCD_INIT(void);
void LCD_STRING(unsigned char *);
void LCD_INTEGER(int);
void LCD_FLOAT(float f_val);

void LCD_COMMAND(unsigned char cmd){

	IOCLR0 = LCD_D;
	IOSET0 = (cmd&0xf0)<<10;
	IOCLR0 = RS;
	IOSET0 = E;
	delay_ms(2);
	IOCLR0 = E;
	
	IOCLR0 = LCD_D;
	IOSET0 = (cmd&0x0f)<<14;
	IOCLR0 = RS;
	IOSET0 = E;
	delay_ms(2);
	IOCLR0 = E;
	
	}
	
void LCD_DATA(unsigned char D){

	IOCLR0 = LCD_D;
	IOSET0 = (D&0xf0)<<10;
	IOSET0 = RS;
	IOSET0 = E;
	delay_ms(2);
	IOCLR0 = E;
	
	IOCLR0 = LCD_D;
	IOSET0 = (D&0x0f)<<14;
	IOSET0 = RS;
	IOSET0 = E;
	delay_ms(2);
	IOCLR0 = E;
	
	}
	

void LCD_INIT(void){
	
  IODIR0 |= LCD_D|RS|E;
	LCD_COMMAND(0x01);
	LCD_COMMAND(0x02);
	LCD_COMMAND(0x0C);
	LCD_COMMAND(0x28);
	
	}

void LCD_STRING(unsigned char *s){
	
	//char p = 0;
	while(*s){
		
		LCD_DATA(*s++);
// 		p++;
// 		if(p==32)
// 			LCD_COMMAND(0x01);
		
	}
}

void LCD_INTEGER(int n){
	
	unsigned char arr[5];
	signed char i =0;
	
	if(n==0)
		LCD_DATA('0');
	
	else{
		
		if(n<0)
		{
			LCD_DATA('-');
			n = -n;
		}
		
		while(n>0){
			
			arr[i++] = n%10;
			n=n/10;
		}
		
		for(i=i-1;i>=0;i--)
		LCD_DATA(arr[i]+48);
		
	}

//  if(n<10){
// 	 LCD_DATA('0');
// 	 LCD_DATA(n+48);
//  }
//  else
//  {
// 	 LCD_DATA((n/10)+48);
// 	 LCD_DATA((n%10)+48);
//  }
 }

 void LCD_FLOAT(float f_val)
{
  int number;
  number = f_val;
  LCD_INTEGER(number);
  LCD_DATA('.');
  number=(f_val-number)*100;
  LCD_INTEGER(number);	
}





	
