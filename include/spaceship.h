#include "config.h"

using namespace std;

class Spaceship
{
  private:
    char charDef;   // character used to define a Spaceship in the map
    int position;   // position of the object in the map matrix
    bool status;    // Spaceship alive || Spaceship dead

  public:
    Spaceship();
    ~Spaceship();
    Spaceship(int pos);
};
