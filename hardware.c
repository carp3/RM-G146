
#include <avr/io.h>
#include "hardware.h"

void init(void){
// Set baud rate (56400@8MHz)
UCSRA=0x00;    
UCSRB=0x08;
UCSRC=0x86; 
UBRRH=0x00;
UBRRL=0x08;
}
