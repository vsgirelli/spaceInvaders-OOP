#include "userSpaceship.h"

using namespace std;

UserSpaceship::UserSpaceship()
  : Spaceship()
{

}

UserSpaceship::~UserSpaceship()
{

}

UserSpaceship::UserSpaceship(int posx, int posy)
  : Spaceship(charUser, posx, posy)
{

}

// Once UserSpaceship is a concrete class that inherit from abstract classes,
// UserSpaceship must implement the pure virtual functions declared in the base classes.
char UserSpaceship::getClass(void) {
  return getCharIcon();
}

/*
 * Implements the user's movimentation.
 * User moving to left -> decrements it's ypos value;
 * User moving to right -> increments it's ypos value;
 */
void UserSpaceship::move(int direction) {
  pair<int, int> pos = getPosition();

  if (direction == LEFT) {
    setPosition(--pos.first, pos.second);
  }
  else if (direction == RIGHT) {
    setPosition(++pos.first, pos.second);
  }
}

void UserSpaceship::shoot(void) {

}
