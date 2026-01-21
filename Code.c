/*-------------------------------------------------------
 Project : Android Controlled Semi-Auto Floor Cleaner
 Controller : 8051 Microcontroller
 Description :
 This program controls the movement of a semi-automatic
 floor cleaning robot using input switches. The robot
 supports forward, backward, left, right movement,
 cleaning motor control, and water pump control.

 Author : Arjun Ambekar
--------------------------------------------------------*/

#include <reg52.h>

/* ----------- Switch Definitions ----------- */
sbit S1 = P2^1;   // Forward
sbit S2 = P2^2;   // Backward
sbit S3 = P2^3;   // Stop
sbit S4 = P2^4;   // Right turn
sbit S5 = P2^5;   // Left turn
sbit S6 = P2^6;   // Cleaning motor
sbit S7 = P2^7;   // Water pump

/* ----------- Motor Control Pins ----------- */
sbit motor_pin_1 = P3^0;
sbit motor_pin_2 = P3^1;
sbit motor_pin_3 = P3^2;
sbit motor_pin_4 = P3^3;

/* ----------- Actuator Pins ----------- */
sbit cleaner_pin = P3^4;
sbit water_pump_pin = P3^5;

/* ----------- Function Prototype ----------- */
void delay(unsigned int);

/* ----------- Main Program ----------- */
void main ()
{
    /* Configure switches as input (logic high) */
    S1 = 1; S2 = 1; S3 = 1;
    S4 = 1; S5 = 1; S6 = 1; S7 = 1;

    P3 = 0x00;   // Clear output port

    while(1)     // Infinite loop
    {
        /* ----------- Forward Motion ----------- */
        if(S1 == 0)
        {
            delay(5);
            motor_pin_1 = 0;
            motor_pin_2 = 1;
            motor_pin_3 = 0;
            motor_pin_4 = 1;
        }

        /* ----------- Backward Motion ----------- */
        else if(S2 == 0)
        {
            delay(5);
            motor_pin_1 = 1;
            motor_pin_2 = 0;
            motor_pin_3 = 1;
            motor_pin_4 = 0;
        }

        /* ----------- Stop ----------- */
        else if (S3 == 0)
        {
            delay(5);
            motor_pin_1 = 0;
            motor_pin_2 = 0;
            motor_pin_3 = 0;
            motor_pin_4 = 0;
        }

        /* ----------- Right Turn ----------- */
        if (S4 == 0)
        {
            delay(5);
            motor_pin_1 = 1;
            motor_pin_2 = 0;
            motor_pin_3 = 0;
            motor_pin_4 = 0;
        }

        /* ----------- Left Turn ----------- */
        if (S5 == 0)
        {
            delay(5);
            motor_pin_1 = 0;
            motor_pin_2 = 0;
            motor_pin_3 = 1;
            motor_pin_4 = 0;
        }

        /* ----------- Cleaning Motor ----------- */
        if (S6 == 0)
        {
            delay(5);
            cleaner_pin = 1;
        }
        else
            cleaner_pin = 0;

        /* ----------- Water Pump ----------- */
        if (S7 == 0)
        {
            delay(5);
            water_pump_pin = 1;
        }
        else
            water_pump_pin = 0;
    }
}

/* ----------- Delay Function ----------- */
void delay (unsigned int z)
{
    unsigned int i, j;
    for(i = 0; i < z; i++)
        for(j = 0; j < 1275; j++);
}
