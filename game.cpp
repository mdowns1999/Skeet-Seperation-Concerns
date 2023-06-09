/***********************************************************************
 * Source File:
 *    GAME
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The file that contains main()
 ************************************************************************/

#include "uiInteract.h"
#include "skeet.h"
#include "skeetUI.h"
#include "point.h"

#define WIDTH  800.0
#define HEIGHT 800.0

Point Bullet::dimensions(WIDTH, HEIGHT);
Point Bird::dimensions(WIDTH, HEIGHT);

 /*************************************
  * All the interesting work happens here, when
  * I get called back from OpenGL to output a frame.
  * When I am finished drawing, then the graphics
  * engine will wait until the proper amount of
  * time has passed and put the drawing on the screen.
  **************************************/
void callBack(const UserInput* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   //Skeet* pSkeet = (Skeet*)p;
   SkeetUI* pSkeetUI = (SkeetUI*)p;

   // handle user input
   pSkeetUI->interact(*pUI);

   // move the stuff
   //pSkeet->animate();
   pSkeetUI->animate();

   // output the stuff
   // if (pSkeet->isPlaying())
   //    pSkeet->drawLevel();
   // else
   //    pSkeet->drawStatus();

   if(pSkeetUI->isPlaying())
      pSkeetUI->drawLevel();
   else
      pSkeetUI->drawStatus();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Skkeep type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // initialize OpenGL
   Point dimensions(WIDTH, HEIGHT);
   UserInput ui(0, NULL,
      "Skeet",
      dimensions);

   // initialize the game class
   SkeetUI skeet(dimensions);

   // set everything into action
   ui.run(callBack, &skeet);

   return 0;
}
