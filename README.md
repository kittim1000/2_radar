# Conversion between GIS and Radar coordinate systems
`conv.c` is a tool for conversion between GIS (lat, lon) and Radar (range, bearing) coordinates. Latitude is in [-90.:90.]; longitude can be either in [0.:360.] or in [-180.:180] as long as consistency is maintained. Range is the distance along the great circle of the globe, while bearing is the angle from the true north in [0.:360.] measured clockwise.

# Method
For GIS to Radar conversion, the following formula in [1] is used:
```
// R = Earth’s radius
dlon = lon2 – lon1;
ran = acos( sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(dlon) ) * R;
bar = atan2( sin(dlon)*cos(lat2), cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(dlon/2) );
```
For Radar to GIS conversion, the formula in [2] is used with modification:
```
lat2 = asin( sin(lat1)*cos(ran) + cos(lat1)*sin(ran)*cos(bar) );
lon2 = lon1 + atan2( sin(bar)*sin(ran)*cos(lat1), cos(ran)-sin(lat1)*sin(lat2) );
```

# Usage
Compile `conv.c` with `-lm` option and run.
The following is displayed:
```
------------------------
  Enter the mode of converion (1 or 2)
  1 for gis to radar (input: lat1, lon1, lat2, lon2; output: range, bearing)
  2 for radar to gis (input: lat1, lon1, range, bearing; output: lat2, lon2)
------------------------
  Enter mode: 
```
Enter 1 or 2. For initial running, instruction on lat and lon input (second line below) is shown.
```
  Enter mode: 1
  Enter lat & lon in degrees without N/S/E/W; Use negative numbers for S/W.
  Enter lat1, lon1, lat2, lon2, separated by white space:
```

For example, 
```
Initial: Wallops Islands, lat: 37N, long: 75W
Final: Puerto Rico, lat: long: 18N, 66W
```
will be entered as 37 -75 18 -66.


The result is
```
  range = 2288.66, bearing = 155.32

  Repeat? (1=yes, 0=no) :
```

For additional test:
```
------------------------
  Enter mode: 1
  Enter lat1, lon1, lat2, lon2, separated by white space: 0 0 80 180

  range = 11119.49, bearing =   0.00

  Repeat? (1=yes, 0=no) : 1
------------------------
  Enter mode: 2
  Enter lat1, lon1, range, bearing, separated by white space: 0 0 11119.49 0

  lat2 =  80.00, lon2 = 180.00

  Repeat? (1=yes, 0=no) :
```

# Reference
[1] http://www.anycalculator.com/longitude.htm 

[2] https://gis.stackexchange.com/questions/5821/calculating-latitude-longitude-x-miles-from-point
