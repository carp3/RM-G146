#include <avr/io.h>
#include "i2c.h"



void i2c_transmit(char address, char reg, char data)
{
	TWCR = 0xA4;                                                  // send a start bit on i2c bus
	while(!(TWCR & 0x80));                                        // wait for confirmation of transmit 
	TWDR = address;                                               // load address of i2c device
	TWCR = 0x84;                                                  // transmit
	while(!(TWCR & 0x80));                                        // wait for confirmation of transmit
	TWDR = reg;
	TWCR = 0x84;                                                  // transmit
	while(!(TWCR & 0x80));                                        // wait for confirmation of transmit
	TWDR = data;
	TWCR = 0x84;                                                  // transmit
	while(!(TWCR & 0x80));                                        // wait for confirmation of transmit
	TWCR = 0x94;                                                  // stop bit
}

unsigned char i2cRead(char address, char reg)
{
char read_data = 0;

   TWCR = 0xA4;                                                  // send a start bit on i2c bus
   while(!(TWCR & 0x80));                                        // wait for confirmation of transmit  
   TWDR = address;                                               // load address of i2c device
   TWCR = 0x84;                                                  // transmit 
   while(!(TWCR & 0x80));                                        // wait for confirmation of transmit
   TWDR = reg;                                                   // send register number to read from
   TWCR = 0x84;                                                  // transmit
   while(!(TWCR & 0x80));                                        // wait for confirmation of transmit

   TWCR = 0xA4;                                                  // send repeated start bit
   while(!(TWCR & 0x80));                                        // wait for confirmation of transmit 
   TWDR = address+1;                                             // transmit address of i2c device with readbit set
   TWCR = 0xC4;                                                  // clear transmit interupt flag
   while(!(TWCR & 0x80));                                        // wait for confirmation of transmit
   TWCR = 0x84;                                                  // transmit, nack (last byte request)
   while(!(TWCR & 0x80));                                        // wait for confirmation of transmit 
   read_data = TWDR;                                             // and grab the target data
   TWCR = 0x94;                                                  // send a stop bit on i2c bus
   return read_data;

}


void i2c_start() 
{  
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); // send start condition  
	while (!(TWCR & (1 << TWINT)));  
}  
  
void i2c_write_byte(char byte)
 {  
	TWDR = byte;              
	TWCR = (1 << TWINT) | (1 << TWEN); // start address transmission  
	while (!(TWCR & (1 << TWINT)));  
}  
  
char i2c_read_byte()
 {  
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN); // start data reception, transmit ACK  
	while (!(TWCR & (1 << TWINT)));  
	return TWDR;  
}  

char i2c_read_last_byte()
 {  
	TWCR = (1 << TWINT) | (1 << TWEN); // start data reception
	while (!(TWCR & (1 << TWINT)));  
	return TWDR;  
}  
  
void i2c_stop() {  
	  TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN); // send stop condition  
}  
