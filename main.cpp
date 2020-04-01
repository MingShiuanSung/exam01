#include "mbed.h"

#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2);


int main()

{

      uLCD.printf("\n107061139\n"); //Default Green on black text

      uLCD.line(10 , 20, 10, 50, 0xFFFFFF);
      uLCD.line(40 , 20, 40, 50, 0xFFFFFF);
      uLCD.line(10 , 20, 40, 20, 0xFFFFFF);
      uLCD.line(10 , 50, 40, 50, 0xFFFFFF);

      wait(30);

}