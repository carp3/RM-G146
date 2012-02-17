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
#include "imu.h"
#include "i2c.h"
#include "imu_a.h"
#include <avr/io.h>

void imu_a_read_data_raw(vector *v)
{
	unsigned char xl,xh,yl,yh,zl,zh;

	i2c_start();
	i2c_write_byte(0x30);
	i2c_write_byte(0xa8);
	i2c_start();		  
	i2c_write_byte(0x31); 
	xl = i2c_read_byte();
	xh = i2c_read_byte();
	yl = i2c_read_byte();
	yh = i2c_read_byte();
	zl = i2c_read_byte();
	zh = i2c_read_last_byte();
	i2c_stop();
    v->x = (xh << 8 | xl) /16;
	v->y = (yh << 8 | yl) /16;
	v->z = (zh << 8 | zl) /16;
}


void imu_a_init(){

i2c_transmit(0x30,0x20,0x3F);

}
