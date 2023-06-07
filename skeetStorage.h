/***************************************************************************
 * Header File:
 *    Skeet Storage
 * Author:
 *    Mike Downs, Ben Painter, Star Balls, Michael Darling, and Andrew Swayze
 * Summary:
 *    Manage game pieces
 ***************************************************************************/

#pragma once
#include <list>
#include "bird.h"
#include "birdLogic.h"
#include "birdUI.h"
#include "bullet.h"
#include "effect.h"
#include "gun.h"
#include "time.h"
#include "score.h"


/*********************************************
* SKEET STORAGE
* Stores game pieces
*********************************************/
class SkeetStorage
{
public:
  // This is a constructor
  SkeetStorage() : gun(Point(800.0, 0.0)), time(), score(), hitRatio() {}

  Gun gun;                       // the gun
  std::list<Bird*> birds;        // all the shootable birds
  std::list<Bullet*> bullets;    // the bullets
  std::list<Effect*> effects;    // the fragments of a dead bird.
  Time time;                     // how many frames have transpired since the beginning
  Score score;                   // the player's score
  HitRatio hitRatio;             // the hit ratio for the birds
   
  // getters
  //Gun* getGun() { return *gun; }
  //Time* getTime() { return *time; }
  //Score* getScore() { return *score; }
  //HitRatio* gethitRatio() { return *hitRation; }
  //Point* getTime() { return *dimensions; }
  //list<Bird*> *getBirds() { return *birds; }
  //list<Bullet*> *getBullets() { return *bullets; }
  //list<Effect*> *getEffects() { return *effects; }

  // setters
};

