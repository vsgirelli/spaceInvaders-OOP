#include "config.h"
#include "spaceship.h"

using namespace std;

class EnemySpaceship : public Spaceship 
{
  private:
    int direction;  // Movimentation direction

  public:
    EnemySpaceship();
    ~EnemySpaceship();
    EnemySpaceship(int posx, int posy, int dir);
    char getClass(void);
    void move(void);
    void shoot(void);
};
