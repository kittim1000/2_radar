#include <stdio.h>
#include <math.h>

main () {
  double lon1, lon2, lat1, lat2, ran1, ran2, bar;
  double a, dlon, dlat;
  double sin(double);
  double cos(double);
  double acos(double);
  double atan2(double, double);
  double pow(double, double);
  double sqrt(double);

  double const pi = 4 * atan(1.);
  double const R = 6371.;

  lat1 = 37.; lat2 = 18.;
  lon1 = 75.; lon2 = 66.;

  dlon = lon2 - lon1;
  dlat = lat2 - lat1;

  ran1 = acos( sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(dlon) ) * R;

//  a = pow(sin(dlat/2),2) + cos(lat1)*cos(lat2) * pow(sin(dlon/2),2);
//  ran2 = R * 2*atan2( sqrt(a), sqrt(1.-a) );

  bar = atan2( sin(dlon)*cos(lat2), cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(dlon/2) );
  bar = bar * 180./pi + 360;
  if (bar > 360) { bar -= 360; }

  printf ("%lf\t%lf\t%lf\n", ran1, bar);
}
