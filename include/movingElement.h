#include "config.h"

using namespace std;

// sobre como funciona herança com várias classes abstratas:
// https://stackoverflow.com/questions/4985993/inheritance-of-abstract-class

// If a class inherit from an abstract class and does not implement
// one of its pure virtual functions, then the derived class is also
// an abstract class.

// Abstract class inherited by all the objects that move.
class MovingElement : public Element
{
  public:
    MovingElement();
    ~MovingElement();
    // A class is abstract if it has at least one pure virtual function,
    // which is a function that is only declared
    // and must be overridden by any concrete derived class.
    void move(void) = 0;
};
