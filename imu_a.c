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
/*
	v->x = (float)((xh << 8 | xl) * (2.0F * Gravity)) / 32768.0F;
	v->y = (float)((yh << 8 | yl) * (2.0F * Gravity)) / 32768.0F;
	v->z = (float)((zh << 8 | zl) * (2.0F * Gravity)) / 32768.0F;
*/
    v->x = (xh << 8 | xl) /16;
	v->y = (yh << 8 | yl) /16;
	v->z = (zh << 8 | zl) /16;
}


void imu_a_init(){

i2c_transmit(0x30,0x20,0x3F);

}
