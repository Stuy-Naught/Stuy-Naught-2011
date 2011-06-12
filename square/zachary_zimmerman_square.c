#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static float state;
static float Point[3];
 
//User01: stuynaught Team: Stuy-Naught Project: testZachary
void ZRUser01(float *myState, float *otherState, float time)
{
if ( state == 0 ) {
 
Point[0] = 0.45;
Point[1] = 0.45;
Point[2] = 0;
 
}
 
if (( state == 1) || ( state == 3 )) {
 
Point[0] = -Point[0];
 
}
 
else if (( state == 2 ) || ( state == 4 )) {
 
Point[1] = -Point[1];
 
}
 
ZRSetPositionTarget(Point);
 
if (sqrt
((myState[0]-Point[0])*(myState[0]-Point[0])
+(myState[1]-Point[1])*(myState[1]-Point[1])
+(myState[2]-Point[2])*(myState[2]-Point[2])) < 0.05) {
 
state = state+1;
 
}
}
void ZRInit01()
{
  state = (float) 0;
  memset(Point,0,sizeof(float)*3);
 
}
//User-defined procedures