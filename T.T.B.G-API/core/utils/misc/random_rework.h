#ifndef _H_RANDOM_REWORK_H_
#define _H_RANDOM_REWORK_H_

#pragma once
#include <random>
#include <string>
#include <vector>

// returns a random number with a minimum value of min,
// and a maximum value of max
static int random(int min, int max)  // range : [min, max)
{
    if (max < min) return 0;
    std::random_device rd;   // obtain a random number from hardware
    std::mt19937 eng(rd());  // seed the generator
    std::uniform_int_distribution<> distr(min, max);  // define the range

    return distr(eng);
}
#endif  // !_H_RANDOM_REWORK_H_
