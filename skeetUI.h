/***************************************************************************
 * Header File:
 *    Skeet UI
 * Author:
 *    Mike Downs, Ben Painter, Star Balls, Michael Darling, and Andrew Swayze
 * Summary:
 *    Interface for the Skeet
 ***************************************************************************/

#pragma once
#include "skeetLogic.h"
#include <string>
using namespace std;

/*********************************************
* SKEET UI
* interface for Skeet
*********************************************/
class SkeetUI
{
public:
   SkeetLogic* pLogic; 

   SkeetUI(Point dimensions) : dimensions(dimensions) {
      pLogic = new SkeetLogic();
   }

   // output everything on the screen
   void drawLevel()  const;    // output the game
   void drawStatus() const;    // output the status information

   void drawBackground(double redBack, double greenBack, double blueBack) const;
   void drawTimer(double percent,
                  double redFore, double greenFore, double blueFore,
                  double redBack, double greenBack, double blueBack) const;

   // handle all user input
   void interact(const UserInput& ui);

   void animate();

   bool isPlaying() {
      return pLogic->isPlaying();
   }

private:
   Point dimensions;              // size of the screen
};

