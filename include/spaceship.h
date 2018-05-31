#include "config.h"

using namespace std;

class Spaceship
{
  private:
    string charDef; // character used to define a Spaceship in the map
    int position;   // position of the object in the map matrix
    int status;     // 1 - Spaceship alive, 0 - Spaceship dead

  public:
    Spaceship();
    ~Spaceship();
    Spaceship(int pos);
};
