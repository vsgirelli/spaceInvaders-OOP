#include "userSpaceship.h"

using namespace std;

UserSpaceship::UserSpaceship()
  : Element()
{

}

UserSpaceship::~UserSpaceship()
{

}

UserSpaceship::UserSpaceship(int posx, int posy)
  : Element(charUser, posx, posy)
{

}

// Once UserSpaceship is a concrete class that inherit from abstract classes,
// UserSpaceship  must implement the pure virtual functions declared in the base classes.
char UserSpaceship::getClass(void) {
  return this.charDef;
}

void UserSpaceship::move(void) {

}

void UserSpaceship::shoot(void) {

}
