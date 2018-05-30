#include <iostream>
#include <fstream> // used for FILE operations
#include <cstdlib> // used for system calls
#include "config.h"

using namespace std;

class Spaceship
{
  private:
    char charDef; // character used to define a Spaceship
    int position; // position in the map matrix
    int status;   // for dead or alive

  public:
    Spaceship();
    ~Spaceship();
    Spaceship(int pos);
};
