#pragma once
#include <avr/io.h>
#include "imu.h"

void imu_g_read_data_raw(vector *v);
void imu_g_read_temp(uint16_t *temp);
void imu_g_init();
