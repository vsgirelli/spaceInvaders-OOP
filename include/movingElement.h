#include "config.h"
#include "element.h"

#pragma once

using namespace std;

// If a class inherit from an abstract class and does not implement
// one of its pure virtual functions, then the derived class is also
// an abstract class.

// Abstract class inherited by all the objects that move.
class MovingElement : public Element
{
  public:
    MovingElement();
    ~MovingElement();
    MovingElement(char def, int posx, int posy);
    // A class is abstract if it has at least one pure virtual function,
    // which is a function that is only declared
    // and must be overridden by any concrete derived class.
    virtual void move(int direction) = 0;
};
