/***************************************************************************
 * Header File:
 *    Bullet Logic
 * Author:
 *    Mike Downs, Ben Painter, Star Balls, Michael Darling, and Andrew Swayze
 * Summary:
 *    Logic for things the bullet does
 ***************************************************************************/
#pragma once

 /*********************************************
 * BULLET LOGIC
 * Logic for things the bullets do
 *********************************************/
class BulletLogic
{
};

/*********************************************
* PELLET Logic
* Logic for Pellet
*********************************************/
class PelletLogic : public BulletLogic
{
};

/*********************************************
* MISSILE Logic
* Logic for Missile
*********************************************/
class MissileLogic : public BulletLogic
{
};

/*********************************************
* Bomb Logic
* Logic for Bomb
*********************************************/
class BombLogic : public BulletLogic
{
};

/*********************************************
* Shrapnel Logic
* Logic for Shrapnel
*********************************************/
class ShrapnelLogic : public BulletLogic
{
};

