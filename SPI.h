// Библиотека для работы с шиной SPI

#include <avr/io.h>

#define SPI_DDR	 DDRB
#define SPI_PORT PORTB
#define SPI_SS 	 PB4
#define SPI_MOSI PB5
#define SPI_MISO PB6
#define SPI_SCK  PB7

void spi_init_master();//функция инициализация шины SPI как мастер
void spi_init_slave();//функция инициализация шины SPI как slave
int8_t spi_transive_master(int8_t data);//передача данных по SPI
int8_t spi_reciver_data();//функция приема данных по SPI
