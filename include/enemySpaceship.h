#include "config.h"
#include "spaceship.h"

using namespace std;

class EnemySpaceship : public Spaceship
{
  public:
    static int direction;
    static int directionSteps;
    EnemySpaceship();
    ~EnemySpaceship();
    EnemySpaceship(int posx, int posy);
    char getClass(void);
    void move(int direction);
    void shoot(void);
};
