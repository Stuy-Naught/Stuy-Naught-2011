#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static int state;
 
//User01: blakeelias Team: Stuy-Naught Project: Square
void ZRUser01(float *myState, float *otherState, float time)
{
float P[3];  // The point to move towards in (x, y, z) coordinates
float dist;  // The distance we are from said point (calculated)
float V[3];  // The velocity we should travel at to reach that point (calculated)
 
if (state == 0) {
    // point (0.5, 0.5, 0), first corner of our square
    P[0] = 0.5;
    P[1] = 0.5;
    P[2] = 0.0;
}
else if (state == 1) {
    P[0] = 0.5;
    P[1] = -0.5;
    P[2] = 0.0;
}
else if (state == 2) {
    P[0] = -0.5;
    P[1] = -0.5;
    P[2] = 0.0;
}
else if (state == 3) {
    P[0] = -0.5;
    P[1] = 0.5;
    P[2] = 0.0;
}
 
//ZRSetPositionTarget(P);  // move towards point P
 
V[0] = P[0] - myState[0];
V[1] = P[1] - myState[1];
V[2] = P[2] - myState[2];
 
mathVecNormalize(V, 3);
V[0] = V[0] * 0.03;
V[1] = V[1] * 0.03;
V[2] = V[2] * 0.03;
 
if (getPercentFuelRemaining() < 8) {
    V[0] = 0;
    V[1] = 0;
    V[2] = 0;
}
ZRSetVelocityTarget(V);
 
dist = sqrt((myState[0]-P[0])*(myState[0]-P[0]) +
            (myState[1]-P[1])*(myState[1]-P[1]) +
            (myState[2]-P[2])*(myState[2]-P[2]));  // find our distance from the corner we're traveling to
 
 
if (dist < 0.05) {
    state = state + 1;  // move to the next corner if we're within 5 cm of the current target
    if (state == 4) {
        state = 0;
    }
}
}
void ZRInit01()
{
  state = (int) 0;
 
}
//User-defined procedures
