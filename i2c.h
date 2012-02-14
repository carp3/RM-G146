#pragma once
#include <avr/io.h>

void i2c_transmit(char address, char reg, char data);
unsigned char i2cRead(char address, char reg);
void i2c_start();
void i2c_write_byte(char byte);
char i2c_read_byte();
char i2c_read_last_byte();
void i2c_stop();
