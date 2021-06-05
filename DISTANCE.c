#include <math.h>
#include "inc/STD_TYPES.h"

#define PI 3.14159265358979323846 //PI CONSTANT
#define EARTH_RADIUS 6371 // EARTH RADIUS IN KM

double deg_to_rad(double deg) { // CHANGE DEGREE TO RADIAN
  return ((deg * PI) / 180);
}

double rad_to_deg(double rad) { // CHANGE RADIAN TO DEGREE
  return ((rad * 180) / PI);
}

//FUNCTION RETURNS DISTANCE IN METRES
//IMPORTANT: HAS TO BE CASTED

