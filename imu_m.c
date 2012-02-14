#include "i2c.h"
#include "imu_m.h"
#include "imu.h"
#include <avr/io.h>




void imu_m_read_data_raw(vector *v)
{
	unsigned char xl,xh,yl,yh,zl,zh;

	i2c_start(); 
	i2c_write_byte(0x3C);
	i2c_write_byte(0x03);
	i2c_start();		 
	i2c_write_byte(0x3D);

	xh = i2c_read_byte();
	xl = i2c_read_byte();
	yh = i2c_read_byte();
	yl = i2c_read_byte();
	zh = i2c_read_byte();
	zl = i2c_read_last_byte();

    v->x = (xh << 8 | xl) /16;
	v->y = (yh << 8 | yl) /16;
	v->z = (zh << 8 | zl) /16;

	i2c_stop();


}


void imu_m_init(){

i2c_transmit(0x3c,0x00,0x18);
i2c_transmit(0x3c,0x02,0x00);

}
