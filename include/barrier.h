#include "config.h"

using namespace std;

class Barrier
{
  private:
    string charDef; // character used to define a Barrier in the map
    int position;   // position of the object in the map matrix
    int status;     // 1 - Barrier alive, 0 - Barrier dead

  public:
    Barrier();
    ~Barrier();
    Barrier(int pos);
};
