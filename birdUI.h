/***************************************************************************
 * Header File:
 *    Bird UI
 * Author:
 *    Mike Downs, Ben Painter, Star Balls, Michael Darling, and Andrew Swayze
 * Summary:
 *    Interface for Bird
 ***************************************************************************/
 
#pragma once
#include "point.h"
#include "bird.h"

/*********************************************
* Bird UI
* Interface for Bird
*********************************************/ 
class BirdUI
{
public:
   virtual void draw(Bird* pBird) = 0;
};

/*********************************************
* STANDARD UI
* Interface for a Standard Bird
*********************************************/
class StandardUI : public BirdUI
{
    //StandardUI(double radius = 25.0);
   void draw(Bird* pBird);
};

/*********************************************
* CRAZY UI
* Interface for a Crazy Bird
*********************************************/
class CrazyUI : public BirdUI
{
   //CrazyUI(double radius = 30.0);
   void draw(Bird* pBird);
};

/*********************************************
* FLOATER UI
* Interface for a Floater Bird
*********************************************/
class FloaterUI : public BirdUI
{
   //FloaterUI(double radius = 30.0);
   void draw(Bird* pBird);
};

/*********************************************
* SINKER UI
* Interface for a Standard Bird
*********************************************/
class SinkerUI : public BirdUI
{
   //SinkerUI(double radius = 30.0);
   void draw(Bird* pBird);
};

