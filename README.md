a simple library for AVR for using RM-G146
The RoBoard Module RM-G146 is fully integrated 9-Axis module, combines 3-axis magneto-resistive sensor and 3-axis accelerometer with the LSM303DLH, and 3-axis angular rate sensor (Gyroscope) with the MPU-3050


## Useage:
```c
vector v;
imu_g_init();
imu_a_init();
imu_m_init();

_delay_ms(100);

while(1)
{ 
  imu_g_read_data_raw(&v);
  printf("X%7i,Y%7i,Z%7i\r\n",v.x, v.y, v.z);
}
```
