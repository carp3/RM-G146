#include "imu.h"



uint16_t raw_roll(vector *v){

return -1 * ((atan2(v->y,v->z)*180)/3.14f);

}


uint16_t raw_pitch(vector *v){

return -1 * ((atan2(v->x,v->z)*180)/3.14f);

}
