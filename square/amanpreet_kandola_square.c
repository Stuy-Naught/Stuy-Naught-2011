#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static int state;

void ZRUser01(float *myState, float *otherState, float time)
{
float target[3] = {0.5, 0.5, 0.0}  
float dist;  
 
if (state == 0) {   
}
else if (state == 1) {
    target[1] = -0.5 ;  
}
else if (state == 2) {
    target[1] = -0.5 ;  
    target[0] = -0.5 ;
}
else if (state == 3) {
    target[0] = -0.5;   
}
 
ZRSetPositionTarget(P);  
 
if (sqrt((myState[0]-P[0])*(myState[0]-P[0]) +
            (myState[1]-P[1])*(myState[1]-P[1]) +
            (myState[2]-P[2])*(myState[2]-P[2])) < 0.05)  
{
    state = state + 1;  
}
}
void  ZRInit01 ()
{
  state = (int) 0;
 
}
//User-defined procedures
