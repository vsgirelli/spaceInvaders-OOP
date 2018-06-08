#include "config.h"
#include "movingElements.h"

using namespace std;

// Abstract class inherited by the two types of spaceships:
// enemy spaceship and user spaceship
class Spaceship : public MovingElement
{
  public:
    Spaceship();
    ~Spaceship();
    Spaceship(char def, int posx, int posy, bool stat);

    // A class is abstract if it has at least one pure virtual function,
    // which is a function that is only declared
    // and must be overridden by any concrete derived class.
    virtual void shot(void) = 0;
    void moveShots(void);
};
