// ���������� ��� ������ � ����� SPI

#include <avr/io.h>

#define SPI_DDR	 DDRB
#define SPI_PORT PORTB
#define SPI_SS 	 PB4
#define SPI_MOSI PB5
#define SPI_MISO PB6
#define SPI_SCK  PB7

void spi_init_master();//������� ������������� ���� SPI ��� ������
void spi_init_slave();//������� ������������� ���� SPI ��� slave
int8_t spi_transive_master(int8_t data);//�������� ������ �� SPI
int8_t spi_reciver_data();//������� ������ ������ �� SPI
