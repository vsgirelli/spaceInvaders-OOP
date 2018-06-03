#include "config.h"

using namespace std;

class Barrier
{
  private:
    char charDef;   // character used to define a Barrier in the map
    int position;   // position of the object in the map matrix
    bool status;    // Barrier alive || Barrier dead

  public:
    Barrier();
    ~Barrier();
    Barrier(int pos);
};
