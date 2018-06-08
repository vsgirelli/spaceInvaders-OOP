#include "config.h"
#include "spaceship.h"

using namespace std;

class EnemySpaceship : public movingElements
{
  private:
    int direction;  // Movimentation direction

  public:
    EnemySpaceship();
    ~EnemySpaceship();
    EnemySpaceship(char def, int posx, int posy, bool stat);
};
