#include "config.h"

using namespace std;

class Enemy: public Spaceship
{
  private:
    string charDef; // character used to define an Enemy in the map
    int position;   // position of the object in the map matrix
    bool status;    // Enemy alive || Enemy dead

  public:
    Enemy();
    ~Enemy();
    Enemy(int pos);
};
