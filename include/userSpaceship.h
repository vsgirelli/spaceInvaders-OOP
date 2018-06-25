#include "config.h"
#include "spaceship.h"

using namespace std;

class UserSpaceship: public Spaceship
{
  public:
    UserSpaceship();
    ~UserSpaceship();
    UserSpaceship(int posx, int posy);
    char getClass(void);
    void move(int direction);
    void shoot(void);
};
