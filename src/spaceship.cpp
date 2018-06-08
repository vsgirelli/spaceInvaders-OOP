#include "spaceship.h"

using namespace std;

Spaceship::Spaceship()
  : MovingElement()
{

}

Spaceship::~Spaceship() {

}

Spaceship::Spaceship(char def, int posx, int posy)
  : MovingElement(def, posx, posy)
{

}

void Spaceship::moveShots(vector<Shot*> shots) {

}
