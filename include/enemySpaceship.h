#include "config.h"
#include "spaceship.h"

using namespace std;

class EnemySpaceship : public Spaceship
{
  public:
    /*
     * Static attributes are class attributes,
     * shared by all the objects from the class.
     */
    static int direction;       // Direction to walk.
    static int directionSteps;  // Number of steps available in the current direction.

    EnemySpaceship();
    ~EnemySpaceship();
    EnemySpaceship(int posx, int posy);
    char getClass(void);
    void move(int direction);
    Shot * shoot(void);
};
