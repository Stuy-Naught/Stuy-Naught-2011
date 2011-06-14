#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static int state;
 
//User01: stuynaught Team: Stuy-Naught Project: kc square
void ZRUser01(float *myState, float *otherState, float time)
{
float P[3] = {0.5, 0.5, 0.0};
float V[3];
float dist;
 
if (state == 1){
    P[1] = -0.5;
    }
else if (state == 2){
    P[0] = -0.5;
    P[1] = -0.5;
    }
else if (state == 3){
    P[0] = -0.5;
    P[1] = 0.5;
    }
 
dist = sqrt((myState[0] - P[0])*(myState[0] - P[0]) +
              (myState[1] - P[1])*(myState[1] - P[1]) +
              (myState[2] - P[2])*(myState[2] - P[2])) ;
 
if (dist < 0.05){
     state = state+1;
     }
      
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
 
//ZRSetPositionTarget(P);
ZRSetVelocityTarget(V);
 
 
if (state == 4) {
    state = 0;
    }   
}
void ZRInit01()
{
  state = (int) 0;
 
}
//User-defined procedures
