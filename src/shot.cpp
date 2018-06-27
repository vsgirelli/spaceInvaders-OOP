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
  return getCharIcon();
}

int Shot::getDirection(){
  return direction;
}

// Once Shot is a concrete class that inherit from abstract classes,
// Shot must implement the pure virtual functions declared in the base classes.
void Shot::move(int direction) {
  pair<int,int> position = getPosition();
  switch (direction) {

    case MOVE_DOWNWARD:
    position.second += 1;
    break;

    case MOVE_UPWARD:
    position.second -=1;
    break;
  }
  setPosition(position);
}
//TODO VAL UML POLOMOFRMISO
void Shot::move() {
  move(direction);
}
