/*
   RM-G146 library for AVR
   Written by Pedram Azimaie <carp3co@gmail.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/
#pragma once
#include <avr/io.h>

void i2c_transmit(char address, char reg, char data);
unsigned char i2cRead(char address, char reg);
void i2c_start();
void i2c_write_byte(char byte);
char i2c_read_byte();
char i2c_read_last_byte();
void i2c_stop();
