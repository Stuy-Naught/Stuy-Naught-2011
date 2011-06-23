#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static int state;
 
//User01: kevinwang Team: Stuy-Naught Project: 2011-05-31
void ZRUser01(float *myState, float *otherState, float time)
{
float P[3] = {0.2, 0.2, 0.0};
 
switch(state % 4) {
    case 1:
        P[0] = -0.2;
        break;
    case 2:
        P[0] = -0.2;
        P[1] = -0.2;
        break;
    case 3:
        P[1] = -0.2;
        break;
}
 
ZRSetPositionTarget(P);
 
if (sqrt((myState[0] - P[0]) * (myState[0] - P[0]) +
    (myState[1] - P[1]) * (myState[1] - P[1]) +
    (myState[2] - P[2]) * (myState[2] - P[2])) < 0.05) {
        state++;
}
}
void ZRInit01()
{
  state = (int) 0;
 
}
//User-defined procedures