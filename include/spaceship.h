#include "config.h"
#include "movingElement.h"
#include "shot.h"

#pragma once

using namespace std;

// If a class inherit from an abstract class and does not implement
// one of its pure virtual functions, then the derived class is also
// an abstract class.

// Abstract class inherited by the two types of spaceships:
// enemy spaceship and user spaceship
class Spaceship : public MovingElement
{
  public:
    Spaceship();
    ~Spaceship();
    Spaceship(char def, int posx, int posy);

    // A class is abstract if it has at least one pure virtual function,
    // which is a function that is only declared
    // and must be overridden by any concrete derived class.
    virtual void shoot(void) = 0;
};
