#include<lpc21xx.h>
#include<string.h>

unsigned char UART0_RX(void);

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
	
		UART0_STRING("AT+CWMODE=1\r\n");
		delay_ms(1000);
	  ESP_Read_Response();
	
		UART0_STRING("AT+CWJAP=\"motog645G_4282\",\"12345678\"\r\n");
		delay_ms(2000);
		ESP_Read_Response();
	

}

void Thingspeak_data(f32 val){	
	
		char str[100];
		char s[100];
	
	
	  sprintf(str,"GET /update?api_key=R4L7PAI0TXJB0CG8&field1=%.2f HTTP/1.1\r\n""Host: api.thingspeak.com\r\n""Connection: close\r\n\r\n",val);
		sprintf(s,"AT+CIPSEND=%d\r\n",strlen(str));
	 
	
		UART0_STRING("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
		delay_ms(2000);
	  ESP_Read_Response();
	
		
		UART0_STRING(s);
		delay_ms(2000);
	  ESP_Read_Response();
		
		UART0_STRING(str);
		delay_ms(15000);
	  ESP_Read_Response();
		
		}




		