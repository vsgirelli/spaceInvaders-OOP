#include "config.h"

using namespace std;

class Barrier
{
  private:
    string charDef; // character used to define a Barrier
    int position;   // position in the map matrix
    int status;     // for dead or alive

  public:
    Barrier();
    ~Barrier();
    Barrier(int pos);
};
