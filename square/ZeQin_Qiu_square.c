#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static int state;
 
//User01: stuynaught Team: Stuy-Naught Project: squarey
void ZRUser01(float *myState, float *otherState, float time)
{
float target[3];
target[0] = 0.5;
target[1] = 0.5;
target[2] = 0;
switch(state % 4){
    case 1:
        target[1] = -0.5;
        break;
    case 2:
        target[0] = -0.5;
        break;
    case 3: 
        target[1] = 0.5;
        break;
    default:
        target[0] = 0.5;
}
if(mathSquare(target[0]-myState[0]) < 0.1 && mathSquare(target[1]-myState[1]) < 0.1){
    state++;
}
ZRSetPositionTarget(target);
}
void ZRInit01()
{
  state = (int) 0.0;
 
}
//User-defined procedures