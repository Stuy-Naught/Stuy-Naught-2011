#include <math.h>
#include <string.h>
#include "ZR_API.h"
#include "ZRGame.h"
#include "math_matrix.h"
#include "spheres_constants.h"
static float searchAngle;
 
//User01: stuynaught Team: Stuy-Naught Project: Paul_Khermouch_Panel_Finder
void ZRUser01(float *myState, float *otherState, float time)
{
float newx = .7 * getPanelSide();
float newvel[3];
float newatt[3];
newvel[1] = 0;
newvel[2] = 0;
newvel[0] = (newx - myState[0]) / 5;
ZRSetVelocityTarget(newvel);
newatt[0] = 0;
newatt[1] = sin(searchAngle);
newatt[2] = cos(searchAngle);
if (!iHavePanel()) {
  ZRSetAttitudeTarget(newatt);
  searchAngle += .2;} //Sight cone is 12 degrees, or PI/15 ~ .2. 
//if (mathAbs(newx - myState[0]) < .05) {
}
void ZRInit01()
{
  searchAngle = (float) 0.0;
 
}
