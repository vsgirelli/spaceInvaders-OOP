#include "config.h"
#include "movingElements.h"

using namespace std;

class Shot: public MovingElement
{
  private:
    int direction;  // Movimentation direction

  public:
    Shot();
    ~Shot();
    Shot(int posx, int posy, int dir);
    char getClass(void);
    void move(void);
};
