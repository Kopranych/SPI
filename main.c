//мигание светодиодов
#include "SPI.h"
#include <avr/io.h>
#include <util/delay.h>

void main()
{
	spi_init_master();

	spi_transive_master(0);
	while(1)
	{	
		for(int i = 0; i<256; i++)
		{
			spi_transive_master(i);
			_delay_ms(50);
		}
		
	}
}
