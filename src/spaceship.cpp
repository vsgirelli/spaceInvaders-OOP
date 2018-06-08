#include "spaceship.h"

using namespace std;

Spaceship::Spaceship()
  : Characteristics(), Behaviors()
{

}

Spaceship::~Spaceship() {

}

Spaceship::Spaceship(int pos) {
  charDef = charSpaceship;
  position = pos;
  status = 1;
}
