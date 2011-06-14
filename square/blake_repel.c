#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
 
//User01: blakeelias Team: Stuy-Naught Project: Center-zap
void ZRUser01(float *myState, float *otherState, float time)
{
float position[3];
float attitude[3];
 
if (!outsideBoundary(otherState)) {
    ZRRepel();
}
 
position[0] = otherState[0] / 3;
position[1] = otherState[1] / 3;
position[2] = otherState[2] / 3;
 
ZRSetPositionTarget(position);
 
attitude[0] = position[0];
attitude[1] = position[1];
attitude[2] = position[2];
 
mathVecNormalize(attitude, 3);
ZRSetAttitudeTarget(attitude);
}
void ZRInit01()
{
 
}
//User-defined procedures
