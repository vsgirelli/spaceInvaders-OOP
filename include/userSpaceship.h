#include "config.h"
#include "spaceship.h"

using namespace std;

class UserSpaceship: public MovingElement
{
  public:
    UserSpaceship();
    ~UserSpaceship();
    UserSpaceship(char def, int posx, int posy, bool stat);
};
