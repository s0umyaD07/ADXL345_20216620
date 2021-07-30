#include <iostream>
#include "ADXL345_function.h"
#include <unistd.h>
#include <pthread.h>

using namespace std;
using namespace exploringRPi;

int main() {
   ADXLADXL345_function345 sensor(1,0x53);
   sensor.setResolution(ADXL345_function::NORMAL);
   sensor.setRange(ADXL345_function::PLUSMINUS_4_G);
   sensor.displayPitchAndRoll();
   sensor.Publish_Message();
   return 0;
}
