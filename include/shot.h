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
    Shot(char def, int posx, int posy, bool stat);
};
