#pragma once
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>

/******************************************************************
 * RANDOM
 * These functions generate a random number.
 ****************************************************************/
// int randomLogicInt(int min, int max)
// {
//    assert(min < max);
//    int num = (rand() % (max - min)) + min;
//    assert(min <= num && num <= max);
//    return num;
// }
// double randomLogicFloat(double min, double max)
// {
//    assert(min <= max);
//    double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
//    assert(min <= num && num <= max);
//    return num;
// }