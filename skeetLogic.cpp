#include "skeetLogic.h"

/************************
 * SKEET ANIMATE
 * move the gameplay by one unit of time
 ************************/
void SkeetLogic::animate()
{
   pStorage->time++;

   // if status, then do not move the game
   if (pStorage->time.isStatus())
   {
     // get rid of the bullets and the birds without changing the score
      pStorage->birds.clear();
      pStorage->bullets.clear();
      pStorage->effects.clear();
     return;
   }

   // spawn
   spawn();

   // move the birds and the bullets
   for (auto element : pStorage->birds)
   {
     element->advance();
     pStorage->hitRatio.adjust(element->isDead() ? -1 : 0);
   }
   for (auto bullet : pStorage->bullets)
     bullet->move(pStorage->effects);
   for (auto effect : pStorage->effects)
     effect->fly();

   // hit detection
   for (auto element : pStorage->birds)
   {
      for (auto bullet : pStorage->bullets)
      {
         if (!element->isDead() && !bullet->isDead() &&
            element->getRadius() + bullet->getRadius() >
            minimumDistance(element->getPosition(), element->getVelocity(),
               bullet->getPosition(), bullet->getVelocity()))
         {
            for (int i = 0; i < 25; i++)
               pStorage->effects.push_back(new Fragment(bullet->getPosition(), bullet->getVelocity()));
            element->kill();
            bullet->kill();
            pStorage->hitRatio.adjust(1);
         }
      }
   }

   // remove the zombie birds
   for (auto it = pStorage->birds.begin(); it != pStorage->birds.end();)
     if ((*it)->isDead())
     {
        pStorage->score.adjust((*it)->getPoints());
        it = pStorage->birds.erase(it);
     }
     else
        ++it;

   // remove zombie bullets
   for (auto it = pStorage->bullets.begin(); it != pStorage->bullets.end(); )
     if ((*it)->isDead())
     {
        (*it)->death(pStorage->bullets);
        it = pStorage->bullets.erase(it);
     }
     else
        ++it;

   // remove zombie fragments
   for (auto it = pStorage->effects.begin(); it != pStorage->effects.end();)
     if ((*it)->isDead())
        it = pStorage->effects.erase(it);
     else
        ++it;
}

/************************
 * SKEET INTERACT
 * handle all user input
 ************************/
void SkeetLogic::interact(const UserInput & ui)
{
   // reset the game
   if (pStorage->time.isGameOver() && ui.isSpace())
   { 
      pStorage->time.reset();
      pStorage->score.reset();
      pStorage->hitRatio.reset();
     return;
   }

   // gather input from the interface
   pStorage->gun.interact(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft());
   Bullet *p = nullptr;

   // a pellet can be shot at any time
   if (ui.isSpace())
     p = new Pellet(pStorage->gun.getAngle());
   // missiles can be shot at level 2 and higher
   else if (ui.isM() && pStorage->time.level() > 1)
     p = new Missile(pStorage->gun.getAngle());
   // bombs can be shot at level 3 and higher
   else if (ui.isB() && pStorage->time.level() > 2)
     p = new Bomb(pStorage->gun.getAngle());
   
   // add something if something has been added
   if (nullptr != p)
   {
     pStorage->bullets.push_back(p);
     pStorage->score.adjust(0 - p->getValue());
   }
   
   // send movement information to all the bullets. Only the missile cares.
   for (auto bullet : pStorage->bullets)
     bullet->input(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft(), ui.isB()); 
}

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int SkeetLogic::random(int min, int max)
{
   
   int num = (rand() % (max - min)) + min;

   return num;
}

/************************
 * SKEET SPAWN
 * lanuch new birds
 ************************/
void SkeetLogic::spawn()
{
   double size;
   switch (pStorage->time.level())
   {
     // in level 1 spawn big birds occasionally
   case 1:
     size = 30.0;
     // spawns when there is nothing on the screen
     if (pStorage->birds.size() == 0 && random(0, 15) == 1)
        pStorage->birds.push_back(new Standard(size, 7.0));

     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Standard(size, 7.0));
     break;

     // two kinds of birds in level 2
   case 2:
     size = 25.0;
     // spawns when there is nothing on the screen
     if (pStorage->birds.size() == 0 && random(0, 15) == 1)
        pStorage->birds.push_back(new Standard(size, 7.0, 12));

     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Standard(size, 5.0, 12));
     // spawn every 3 seconds
     if (random(0, 3 * 30) == 1)
        pStorage->birds.push_back(new Sinker(size));
     break;

     // three kinds of birds in level 3
   case 3:
     size = 20.0;
     // spawns when there is nothing on the screen
     if (pStorage->birds.size() == 0 && random(0, 15) == 1)
        pStorage->birds.push_back(new Standard(size, 5.0, 15));

     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Standard(size, 5.0, 15));
     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Sinker(size, 4.0, 22));
     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Floater(size));
     break;

     // three kinds of birds in level 4
   case 4:
     size = 15.0;
     // spawns when there is nothing on the screen
     if (pStorage->birds.size() == 0 && random(0, 15) == 1)
        pStorage->birds.push_back(new Standard(size, 4.0, 18));

     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Standard(size, 4.0, 18));
     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Sinker(size, 3.5, 25));
     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Floater(size, 4.0, 25));
     // spawn every 4 seconds
     if (random(0, 4 * 30) == 1)
        pStorage->birds.push_back(new Crazy(size));
     break;

   default:
     break;
   }
}

bool SkeetLogic::isPlaying() const { return pStorage->time.isPlaying(); }