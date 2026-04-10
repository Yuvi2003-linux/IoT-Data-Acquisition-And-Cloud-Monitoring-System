#include<lpc21xx.h>
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

#include "UART_header.h"
#include "SPI_header.h"
#include "lcd_4bit_1.h"
#include "wifi_header.h"
#define ch 1



int main(){
	
	u32 x=0;
	f32 val;
	
	PINSEL0 |= 0x1505;
	
	UART0_CONFIG();
	SPI0_INIT();
	LCD_INIT();
	WiFi_init();
	
	while(x++<20){
	LCD_COMMAND(0x80);
	LCD_COMMAND(0x1C);
	LCD_STRING("IoT Based Data Acquisition");
	LCD_COMMAND(0xC0);
	LCD_COMMAND(0x1C);
	LCD_STRING("And Cloud Monitoring System");
	delay_ms(50);	 //before 20 ms
	
	}
	
	delay_ms(500);
	LCD_COMMAND(0x01);
	
while(1){
		//delay_sec(2);
		val = ADC_TEMP_READ(ch);
	
		delay_sec(1); //before 2s
	
   	UART0_STRING("Temperature: ");
		UART0_FLOAT(val);
	  UART0_STRING("\n");
	  //delay_sec(5);
	
		LCD_COMMAND(0x80);
	  LCD_STRING("Temperature: ");
	  LCD_COMMAND(0xC0);
		LCD_FLOAT(val);
	  
		Thingspeak_data(val);
}
}	