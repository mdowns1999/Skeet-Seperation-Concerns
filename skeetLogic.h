/***************************************************************************
 * Header File:
 *    Skeet Logic
 * Author:
 *    Mike Downs, Ben Painter, Star Balls, Michael Darling, and Andrew Swayze
 * Summary:
 *    Logic for Skeet
 ***************************************************************************/
#pragma once
#include "uiInteract.h"
#include "skeetStorage.h"
//#include "birdLogic.h"
//#include "birdLogic.h"

class SkeetStorage;

/*********************************************
* SKEET LOGIC
* Logic for Skeet
*********************************************/
class SkeetLogic
{
public:
  SkeetLogic() {
     pStorage = new SkeetStorage();
  }
  
  SkeetStorage* pStorage;

  // getters
  //SkeetStorage* getStorage() { return pStorage; }
  //Time* getTime() { return *time; }

  // handle all user input
  void interact(const UserInput& ui);

  // move the gameplay by one unit of time
  void animate();

  // is the game currently playing right now?
  bool isPlaying() const;

private:
  
   //Builder Function
   Bird* buildStandard(double radius = 25.0, double speed = 5.0, int points = 10);
   Bird* buildFloater(double radius = 30.0, double speed = 5.0, int points = 15);
   Bird* buildCrazy(double radius = 30.0, double speed = 4.5, int points = 30);
   Bird* buildSinker(double radius = 30.0, double speed = 4.5, int points = 20);

  // generate new birds
  void spawn();
  int random(int min, int max);
};

