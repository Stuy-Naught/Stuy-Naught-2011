#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static int state;
 
//User01: stuynaught Team: Stuy-Naught Project: SQUARE
void ZRUser01(float *myState, float *otherState, float time)
{
float P[3];  // The point to move towards in (x, y, z) coordinates
float dist;  // The distance we are from said point
 
P[0] = 0.5;
P[1] = 0.5;
P[2] = 0.0; // point (0.5, 0.5, 0), first corner of our square
 
if (state == 0) {
    // Don't need to do anything extra.
    // The other states give the three other corners of the square.
}
else if (state == 1) {
    P[1] = P[1] * -1;  // negate x
}
else if (state == 2) {
    P[1] = P[1] * -1;  //negate x and y
    P[0] = P[0] * -1;
}
else if (state == 3) {
    P[0] = P[0] * -1;   // negate y
}
 
ZRSetPositionTarget(P);  // move towards point P
 
dist = sqrt((myState[0]-P[0])*(myState[0]-P[0]) +
            (myState[1]-P[1])*(myState[1]-P[1]) +
            (myState[2]-P[2])*(myState[2]-P[2]));  // find our distance from the corner we're traveling to
 
if (dist < 0.05) {
    state = state + 1;  // move to the next corner if we're within 5 cm of the current target
}
}
void ZRInit01()
{
  state = (int) 0;
 
}
//User-defined procedures
