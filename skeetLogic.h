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
  //Time time;
  //int score;
  
  // generate new birds
  void spawn();
  int random(int min, int max);
};

