/***********************************************************************
 * Source File:
 *    Bird Logic
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Logic to kill things with a bullet
 ************************************************************************/
  
#include "birdLogic.h"


 /******************************************************************
  * RANDOM
  * These functions generate a random number.
  ****************************************************************/
int randomLogicInt(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);
   return num;
}
double randomLogicFloat(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   assert(min <= num && num <= max);
   return num;
}

/***************************************************************/
/***************************************************************/
/*                            ADVANCE                          */
/***************************************************************/
/***************************************************************/

/*********************************************
* STANDARD ADVANCE
* How the standard bird moves - inertia and drag
*********************************************/
void StandardLogic::advance(Bird *pBird)
{
   // small amount of drag
   pBird->v *= 0.995;

   // inertia
   pBird->pt.add(pBird->v);

   // out of bounds checker
   if (isOutOfBounds(pBird))
   {
      pBird->kill();
      pBird->points *= -1; // points go negative when it is missed!
   }
}

/*********************************************
 * FLOATER ADVANCE
 * How the floating bird moves: strong drag and anti-gravity
 *********************************************/
void FloaterLogic::advance(Bird *pBird)
{
   // large amount of drag
   pBird->v *= 0.990;

   // inertia
   pBird->pt.add(pBird->v);

   // anti-gravity
   pBird->v.addDy(0.05);

   // out of bounds checker
   if (isOutOfBounds(pBird))
   {
      pBird->kill();
      pBird->points *= -1; // points go negative when it is missed!
   }
}

/*********************************************
 * CRAZY ADVANCE
 * How the crazy bird moves, every half a second it changes direciton
 *********************************************/
void CrazyLogic::advance(Bird *pBird)
{
   // erratic turns every half a second or so
   if (randomLogicInt(0, 15) == 0)
   {
      pBird->v.addDy(randomLogicFloat(-1.5, 1.5));
      pBird->v.addDx(randomLogicFloat(-1.5, 1.5));
   }

   // inertia
   pBird->pt.add(pBird->v);

   // out of bounds checker
   if (isOutOfBounds(pBird))
   {
      pBird->kill();
      pBird->points *= -1; // points go negative when it is missed!
   }
}

/*********************************************
 * SINKER ADVANCE
 * How the sinker bird moves, no drag but gravity
 *********************************************/
void SinkerLogic::advance(Bird *pBird)
{
   // gravity
   pBird->v.addDy(-0.07);

   // inertia
   pBird->pt.add(pBird->v);

   // out of bounds checker
   if (isOutOfBounds(pBird))
   {
      pBird->kill();
      pBird->points *= -1; // points go negative when it is missed!
   }
}