#include<LPC21XX.H>


void UART0_CONFIG(void){
	
	//PINSEL0 |= 0x5;
	U0LCR = 0X83;
	U0DLL = 97;
	U0DLM = 0;
	U0LCR = 0X03;
	 	
}

void UART0_TX(unsigned char txByte){
	
	U0THR = txByte;
	while(((U0LSR>>5)&1)==0); 		

}


unsigned char UART0_RX(void){
	
	while((U0LSR&1)==0);
	return U0RBR;
	
}

void UART0_STRING(unsigned char *s)
{
	while(*s)
		UART0_TX(*s++);
}

void UART0_INTEGER(int n){
if(n<10){
	 UART0_TX('0');
	 UART0_TX(n+48);
 }
 else
 {
	 UART0_TX((n/10)+48);
	 UART0_TX((n%10)+48);
 }
}

void UART0_FLOAT(float f_val)
{
  int number;
  number = f_val;
  UART0_INTEGER(number);
  UART0_TX('.');
  number=(f_val-number)*100;
  UART0_INTEGER(number);	
}

