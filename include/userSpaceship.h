#include "config.h"
#include "spaceship.h"

using namespace std;

class UserSpaceship: public Spaceship
{
  private:
    bool alive;

  public:
    UserSpaceship();
    ~UserSpaceship();
    UserSpaceship(int posx, int posy);
    char getClass(void);
    void move(int direction);
    bool isAlive(void);
    void setDead(void);
    Shot* shoot(void);
};
