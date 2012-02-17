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

// Atmega32A@8MHz 

#include <avr/io.h>
#include <stdio.h>
#include <string.h>    
#include <stdlib.h>  
#include <util/delay.h>

#include "i2c.h"
#include "hardware.h"

#include "imu.h"


static int uart_putchar(char c, FILE *stream);


static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,
                                             _FDEV_SETUP_WRITE);


vector v;





double sss;

int main(void)
    {
	TWBR = 32; // Init I2C (100KHz@8MHz)
    init();

    stdout = &mystdout;
	printf("Initing....");
	_delay_ms(1000);
	imu_g_init();
	imu_a_init();
	imu_m_init();
	printf("Done\r\n");

	_delay_ms(100);

    while(1)
	{ 
	imu_g_read_data_raw(&v);
	printf("X%7i,Y%7i,Z%7i\r\n",v.x, v.y, v.z);


	}

      return 0;
    }





static int
uart_putchar(char c, FILE *stream)
{
if (c == '\n')
   uart_putchar('\r', stream);
loop_until_bit_is_set(UCSRA, UDRE);
UDR = c;
return 0;
}
