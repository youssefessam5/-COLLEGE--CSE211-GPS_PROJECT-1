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

double calc_Distance(double lat1, double lon1, double lat2, double lon2) {
  double diff, dist;
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
  else {
    diff = lon1 - lon2;
    dist = (sin(deg_to_rad(lat1)) * sin(deg_to_rad(lat2))) + (cos(deg_to_rad(lat1)) * cos(deg_to_rad(lat2)) * cos(deg_to_rad(diff)));
    dist = acos(dist) * EARTH_RADIUS * 1000;
    return dist;
  }
}

