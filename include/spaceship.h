#include "config.h"

using namespace std;

class Spaceship
{
  private:
    string charDef; // character used to define a Spaceship
    int position; // position in the map matrix
    int status;   // for dead or alive

  public:
    Spaceship();
    ~Spaceship();
    Spaceship(int pos);
};
