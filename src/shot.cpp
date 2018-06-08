#include "shot.h"

using namespace std;

Shot::Shot()
  : MovingElement()
{

}

Shot::~Shot()
{

}

Shot::Shot(int posx, int posy, int dir)
  : MovingElement(charShot, posx, posy)
{
  direction = dir;
}

// Once Shot is a concrete class that inherit from abstract classes,
// Shot must implement the pure virtual functions declared in the base classes.
char Shot::getClass(void) {
  return getCharDef();
}

void Shot::move(void) {

}
