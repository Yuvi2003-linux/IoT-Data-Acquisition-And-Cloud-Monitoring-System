#include<LPC21XX.H>
#define SPI_SPEED 100000
#define CCLK 60000000
#define PCLK (CCLK/4)
#define SPI_RATE (PCLK/SPI_SPEED)
#define MSTR_bit 5
#define MODE_3 (1<<3)|(1<<4)
#define CS 7
#define SPIF_bit 7

void SPI0_INIT(void){
	
	//PINSEL0 |= 0x1500;
	S0SPCCR = SPI_RATE;
	S0SPCR = (1<<MSTR_bit)|(MODE_3);
	
	IODIR0 |= 1<<CS;
	IOSET0 = 1<<CS;
	
}

u8 SPI0(u8 data)
{
	u8 stat;
	stat = S0SPSR;
	S0SPDR = data;
	
	while(((S0SPSR>>SPIF_bit)&1) == 0);
	return S0SPDR;
}
	
f32 ADC_TEMP_READ(channelno){
	
		u8 hbyte,lbyte;
		f32 ADC_VAL;
		
		IOCLR0 = 1<<CS;
	  
		SPI0(0x06);
		hbyte = SPI0(channelno<<6);
		lbyte = SPI0(0x00);
	
		IOSET0 = 1<<CS;
	  
	  ADC_VAL = ((hbyte&0x0f)<<8)|lbyte;
		return (ADC_VAL*5.0*100)/(4096.0);
	  //return ADC_VAL;
	
}
	