#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static int state;
static float pos[3];
 
//User01: stuynaught Team: Stuy-Naught Project: squares
void ZRUser01(float *myState, float *otherState, float time)
{
float mypos[3];
int i = 0;
float dist;
for (i = 0; i < 3; i++) {
    mypos[i] = myState[i];}
dist = mathSquare(mathVecMagnitude(mypos, 3)) + mathSquare(mathVecMagnitude(pos, 3)) - 2 * mathVecInner(mypos, pos, 3);
dist = sqrt(dist);
if (dist < .05) {
if (state % 4 == 0) {
    pos[0] = .5;}
else if (state % 4 == 1) {
    pos[1] = .5;}
else if (state % 4 == 2) {
    pos[0] = -.5;}
else {
    pos[1] = -.5;}
state++;}
ZRSetPositionTarget(pos);
}
void ZRInit01()
{
  state = (int) 0;
  memset(pos,0,sizeof(float)*3);
 
}
//User-defined procedures