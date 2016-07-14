#include "SPI.h"





void spi_init_master()
{
	SPI_DDR |= 1<<SPI_SS|1<<SPI_MOSI|1<<SPI_SCK;
	SPI_DDR &=~(1<<SPI_MISO);
	SPI_PORT&=~(1<<SPI_SS|1<<SPI_MOSI|1<<SPI_SCK|1<<SPI_MISO);
	SPCR |=1<<SPE|1<<MSTR;//�������� SPI � ����� Master
}

void spi_init_slave()
{
	SPI_DDR &= ~(1<<SPI_SS|1<<SPI_MOSI|1<<SPI_SCK);
	SPI_DDR |=1<<SPI_MISO;
	SPI_PORT&=~(1<<SPI_SS|1<<SPI_MOSI|1<<SPI_SCK|1<<SPI_MISO);
	SPCR |=1<<SPE;//�������� SPI � ����� Slave
}

int8_t spi_transive_master(int8_t data)
{
	SPDR = data;
	while(!(SPSR&(1<<SPIF)));//���� ���� ������ �����������
	SPI_PORT|= 1<<SPI_SS;//����� �����
	SPI_PORT&= ~(1<<SPI_SS);//���� ��� ������ ������ �����
	return SPDR;
}

int8_t spi_reciver_data()
{
	SPI_PORT&= ~(1<<SPI_SS);
	SPDR = data;
	while(!(SPSR&(1<<SPIF)));//���� ���� ������ �� �����������
	return SPDR;
}
