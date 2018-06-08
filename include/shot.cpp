#include "shot.h"

using namespace std;

Shot::Shot()
  : Element()
{

}

Shot::~Shot()
{

}

Shot::Shot(int posx, int posy, int dir)
  : Element(charShot, posx, posy)
{
  this.direction = dir;
}

// Once Shot is a concrete class that inherit from abstract classes,
// Shot must implement the pure virtual functions declared in the base classes.
char Shot::getClass(void) {
  return this.charDef;
}

void Shot::move(void) {

}
