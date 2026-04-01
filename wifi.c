#include <lpc21xx.h>
#include "UART_header.h"
#include "delay_header.h"


void ESP_Read_Response(void)
{
    char ch;
	  int i;
    for( i=0;i<200;i++)
    {
        if(U0LSR & 1)
        {
            ch = U0RBR;
            UART0_TX(ch);   // echo back to terminal
        }
    }
}


void WiFi_init(void){

    UART0_STRING("AT\r\n");
    delay_ms(1000);
		ESP_Read_Response();

    UART0_STRING("AT+GMR\r\n");   // firmware version
    delay_ms(1000);
		ESP_Read_Response();

    UART0_STRING("AT+CWMODE=1\r\n");
    delay_ms(1000);
		ESP_Read_Response();
}


int main(){

	   PINSEL0 = 0x05;
     WiFi_init();
	 
	 }