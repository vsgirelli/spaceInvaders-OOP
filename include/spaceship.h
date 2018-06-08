#include "config.h"
#include "movingElements.h"

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

    // A class is abstract if it has at least one pure virtual function,
    // which is a function that is only declared
    // and must be overridden by any concrete derived class.
    virtual void shoot(void) = 0;
    void moveShots(vector<Shot*> shots);
};
