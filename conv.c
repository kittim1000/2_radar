#include <stdio.h>
#include <math.h>

int g2r (double, double, double, double, double*, double*);
int r2g (double, double, double, double, double*, double*);

double const R = 6371.;

void main () {

  int mode, ind = 1;
  double lon1, lon2, lat1, lat2, ran, bar;

  printf ("------------------------\n  Enter the mode of converion (1 or 2)\n");
  printf ("  1 for gis to radar (input: lat1, lon1, lat2, lon2; output: range, bearing)\n");
  printf ("  2 for radar to gis (input: lat1, lon1, range, bearing; output: lat2, lon2)\n");

  while (ind) {

    printf ("------------------------\n  Enter mode: ");
    scanf("%d", &mode);

    if (mode == 1) {
      printf("  Enter lat1, lon1, lat2, lon2, separated by white space: ");
      scanf("%lf%lf%lf%lf", &lat1, &lon1, &lat2, &lon2);

      g2r (lat1, lon1, lat2, lon2, &ran, &bar);
      printf ("\n  range = %6.2lf, bearing = %6.2lf\n\n", ran, bar);
    }

    else if (mode == 2) {
      printf("  Enter lat1, lon1, range, bearing, separated by white space: ");
      scanf("%lf%lf%lf%lf", &lat1, &lon1, &ran, &bar);

      r2g (lat1, lon1, ran, bar, &lat2, &lon2);
      printf ("\n  lat2 = %6.2lf, lon2 = %6.2lf\n\n", lat2, lon2);
    }
    else { printf ("  Wrong input\n"); }

    printf("  Repeat? (1=yes, 0=no) : ");
    scanf("%d", &ind);
  }
  printf("  Good bye!\n");
}

int g2r(double lat1, double lon1, double lat2, double lon2, double* ran, double* bar) {

  double dlon;

  lat1 *= M_PI/180;
  lat2 *= M_PI/180;
  lon1 *= M_PI/180;
  lon2 *= M_PI/180;

  dlon = lon2 - lon1;

  *ran = acos( sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(dlon) ) * R;

  *bar = atan2( sin(dlon)*cos(lat2), cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(dlon/2) );
  *bar = *bar * 180./M_PI + 360;
  if (*bar > 360) { *bar -= 360; }
}

int r2g(double lat1, double lon1, double ran, double bar, double* lat2, double* lon2) {

  lat1 *= M_PI/180;
  lon1 *= M_PI/180;
  ran = ran / R;
  bar *= M_PI/180.;

  *lat2 = asin( sin(lat1)*cos(ran) + cos(lat1)*sin(ran)*cos(bar) );
  *lat2 *= 180./M_PI;

//  *lon2 = lon1 - asin( sin(bar)*sin(ran)/cos(*lat2) );
  *lon2 = lon1 - atan2( sin(bar)*sin(ran)*cos(lat1), cos(ran)-sin(lat1)*sin(*lat2) );
  *lon2 = *lon2 * 180./M_PI + 360;
  if (*lon2 > 360) { *lon2 -= 360; }
}
