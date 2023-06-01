/***************************************************************************
 * Header File:
 *    Bullet UI
 * Author:
 *    Mike Downs, Ben Painter, Star Balls, Michael Darling, and Andrew Swayze
 * Summary:
 *    Interface for the bullet
 ***************************************************************************/

#pragma once

 /*********************************************
 * BULLET UI
 * Interface for Bullet
 *********************************************/
class BulletUI
{
};

/*********************************************
* PELLET UI
* Interface for Pellet
*********************************************/
class PelletUI : public BulletUI
{
};

/*********************************************
* Missile UI
* Interface for Missile
*********************************************/
class MissileUI : public BulletUI
{
};

/*********************************************
* Bomb UI
* Interface for Bomb
*********************************************/
class BombUI : public BulletUI
{
}; 

/*********************************************
* Shrapnel UI
* Interface for Shrapnel
*********************************************/
class ShrapnelUI : public BulletUI
{
};

