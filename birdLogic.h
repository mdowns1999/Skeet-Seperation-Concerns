/***************************************************************************
 * Header File:
 *    Bird Logic
 * Author:
 *    Mike Downs, Ben Painter, Star Balls, Michael Darling, and Andrew Swayze
 * Summary:
 *    Logic for things the bird does
 ***************************************************************************/
  
#pragma once
#include "bird.h"
#include <assert.h>
//#include "random.h"


 /*********************************************
 * BIRD LOGIC
 * Logic for things the bird does
 *********************************************/
class BirdLogic
{
public:
   virtual void advance(Bird *pBird) = 0;

   bool isOutOfBounds(Bird* pBird) const
   {
      return (pBird->pt.getX() < -pBird->radius || pBird->pt.getX() >= pBird->dimensions.getX() + pBird->radius ||
         pBird->pt.getY() < -pBird->radius || pBird->pt.getY() >= pBird->dimensions.getY() + pBird->radius);
   }
};

/*********************************************
* STANDARD Logic
* Logic for a Standard Bird
*********************************************/
class StandardLogic : public BirdLogic
{
   void advance(Bird *pBird);
};

/*********************************************
* Crazy Logic
* Logic for a Crazy Bird
*********************************************/
class CrazyLogic : public BirdLogic
{
   void advance(Bird *pBird);
};

/*********************************************
* Floater Logic
* Logic for a Floater Bird
*********************************************/
class FloaterLogic : public BirdLogic
{
   void advance(Bird *pBird);
};

/*********************************************
* SINKER Logic
* Logic for a Sinker Bird
*********************************************/
class SinkerLogic : public BirdLogic
{
   void advance(Bird *pBird);
};

