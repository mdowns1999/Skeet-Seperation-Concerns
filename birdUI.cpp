#include "birdUI.h"
 
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12 
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32
 
 
 /***************************************************************/
/***************************************************************/
/*                             DRAW                            */
/***************************************************************/
/***************************************************************/

/************************************************************************
 * DRAW Disk
 * Draw a filled circule at [center] with size [radius]
 *************************************************************************/
void drawDisk(const Point& center, double radius,
              double red, double green, double blue)
{
   const double increment = M_PI / radius;  // bigger the circle, the more increments

   // begin drawing
   glBegin(GL_TRIANGLES);
   glColor3f((GLfloat)red /* red % */, (GLfloat)green /* green % */, (GLfloat)blue /* blue % */);

   // three points: center, pt1, pt2
   Point pt1;
   pt1.setX(center.getX() + (radius * cos(0.0)));
   pt1.setY(center.getY() + (radius * sin(0.0)));
   Point pt2(pt1);

   // go around the circle
   for (double radians = increment;
      radians <= M_PI * 2.0 + .5;
      radians += increment)
   {
      pt2.setX(center.getX() + (radius * cos(radians)));
      pt2.setY(center.getY() + (radius * sin(radians)));

      glVertex2f((GLfloat)center.getX(), (GLfloat)center.getY());
      glVertex2f((GLfloat)pt1.getX(), (GLfloat)pt1.getY());
      glVertex2f((GLfloat)pt2.getX(), (GLfloat)pt2.getY());

      pt1 = pt2;
   }

   // complete drawing
   glEnd();
}
 
 
 
 
 /*********************************************
 * STANDARD DRAW
 * Draw a standard bird: blue center and white outline
 *********************************************/
void StandardUI::draw(Bird *pBird)
{
   if (!pBird->isDead())
   {
      drawDisk(pBird->pt, pBird->radius - 0.0, 1.0, 1.0, 1.0); // white outline
      drawDisk(pBird->pt, pBird->radius - 3.0, 0.0, 0.0, 1.0); // blue center
   }
}

/*********************************************
 * FLOATER DRAW
 * Draw a floating bird: white center and blue outline
 *********************************************/
void FloaterUI::draw(Bird* pBird)
{
   if (!pBird->isDead())
   {
      drawDisk(pBird->pt, pBird->radius - 0.0, 0.0, 0.0, 1.0); // blue outline
      drawDisk(pBird->pt, pBird->radius - 4.0, 1.0, 1.0, 1.0); // white center
   }
}

/*********************************************
 * CRAZY DRAW
 * Draw a crazy bird: concentric circles in a course gradient
 *********************************************/
void CrazyUI::draw(Bird* pBird)
{
   if (!pBird->isDead())
   {
      drawDisk(pBird->pt, pBird->radius * 1.0, 0.0, 0.0, 1.0); // bright blue outside
      drawDisk(pBird->pt, pBird->radius * 0.8, 0.2, 0.2, 1.0);
      drawDisk(pBird->pt, pBird->radius * 0.6, 0.4, 0.4, 1.0);
      drawDisk(pBird->pt, pBird->radius * 0.4, 0.6, 0.6, 1.0);
      drawDisk(pBird->pt, pBird->radius * 0.2, 0.8, 0.8, 1.0); // almost white inside
   }
}

/*********************************************
 * SINKER DRAW
 * Draw a sinker bird: black center and dark blue outline
 *********************************************/
void SinkerUI::draw(Bird* pBird)
{
   if (!pBird->isDead())
   {
      drawDisk(pBird->pt, pBird->radius - 0.0, 0.0, 0.0, 0.8);
      drawDisk(pBird->pt, pBird->radius - 4.0, 0.0, 0.0, 0.0);
   }
}