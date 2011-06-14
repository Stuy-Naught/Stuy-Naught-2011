#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static int state;
 
//User01: stuynaught Team: Stuy-Naught Project: move2.718
void ZRUser01(float *myState, float *otherState, float time)
{
float P[3] = {0.25, 0.25, 0};
 
if (getPercentFuelRemaining() < 10) {
myState[0] = P[0];
myState[1] = P[1];
myState[2] = P[2];
}
if (state == 0) {
}
else
if (state == 1) {
    P[1] = -0.25;
}
else
if (state == 2) {
    P[0] = -0.25;
    P[1] = -0.25;
}
else
if (state == 3) {
    P[0] = -0.25;
}
 
ZRSetPositionTarget(P);
if ( sqrt((myState[0] - P[0])*(myState[0] - P[0]) +
     (myState[1] - P[1])*(myState[1] - P[1]) +
     (myState[2] - P[2])*(myState[2] - P[2]))  < 0.05 ) {
      
     state = state+1;
      
}
 
if (state == 4) {
state = 0;
}
 
 
}
void ZRInit01()
{
  state = (int) 0;
 
}
//User-defined procedures