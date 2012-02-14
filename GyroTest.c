
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

int16_t x,y,z;
vector v;


uint16_t temp;


double sss;

int main(void)
    {
	  TWBR = 32;
      init();
	  TWBR = 32;
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
//	imu_g_read_data_raw(&x,&y,&z);
imu_a_read_data_raw(&v);
	//imu_g_read_temp(&temp);
	printf("X%7i,Y%7i,Z%7i,R%7i,P%7i\r\n",v.x, v.y, v.z,raw_roll(&v),raw_pitch(&v));

//printf("0x%04x\r\n",x);
//printf("%u\r\n",x);
        //printf("%i\r\n",x);

//	_delay_ms(100);

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
