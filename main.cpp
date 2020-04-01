#include "mbed.h"

#include "uLCD_4DGL.h"

// LED = D7

// uLCD
uLCD_4DGL uLCD(D1, D0, D2);

// PWM
PwmOut PWM1(D7);
AnalogIn Ain(A0);

// data to pc
Serial pc( USBTX, USBRX );
float ADCdata;


int main()

{
    // uLCD
      uLCD.printf("\n107061139\n"); //Default Green on black text

      uLCD.line(10 , 20, 10, 50, 0xFFFFFF);
      uLCD.line(40 , 20, 40, 50, 0xFFFFFF);
      uLCD.line(10 , 20, 40, 20, 0xFFFFFF);
      uLCD.line(10 , 50, 40, 50, 0xFFFFFF);
      wait(1);

    // PWM
    PWM1.period(0.001f);      // 4 second period

    while (1) {
        for (float i = 0.0f; i <= 1.0f; i += 0.1f) {
            PWM1.write(i);      // 50% duty cycle, relative to period
            ADCdata = PWM1;
            pc.printf("%1.3f\r\n", ADCdata);
            wait(0.1);
        }

        for (float i = 1.0f; i >= 0.0f; i -= 0.1f) {
            PWM1.write(i);      // 50% duty cycle, relative to period
            ADCdata = PWM1;
            pc.printf("%1.3f\r\n", ADCdata);
            wait(0.1);
        }
    }

     

}