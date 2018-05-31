#include "spaceship.h"

using namespace std;

Spaceship::Spaceship() {

}

Spaceship::~Spaceship() {

}

Spaceship::Spaceship(int pos) {
  charDef = charSpaceship;
  position = pos;
  status = 1;
}
