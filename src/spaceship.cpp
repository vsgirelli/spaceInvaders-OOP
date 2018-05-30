#include "spaceship.h"

using namespace std;

Spaceship::Spaceship() {

}

Spaceship::~Spaceship() {

}

Spaceship::Spaceship(int pos) {
  charDef = '@';
  position = pos;
  status = 1;
}
