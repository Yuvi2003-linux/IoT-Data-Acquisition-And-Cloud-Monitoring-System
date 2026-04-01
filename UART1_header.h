#include<LPC21XX.H>


void UART1_CONFIG(void){
	
	PINSEL0 |= 0x50000;
	U1LCR = 0X83;
	U1DLL = 97;
	U1DLM = 0;
	U1LCR = 0X03;
	 	
}

void UART1_TX(unsigned char txByte){
	
	U1THR = txByte;
	while(((U1LSR>>5)&1)==0); 		

}


unsigned char UART1_RX(void){
	
	while((U1LSR&1)==0);
	return U1RBR;
	
}

void UART1_STRING(unsigned char *s)
{
	while(*s)
		UART1_TX(*s++);
}

