#include "userSpaceship.h"

using namespace std;

UserSpaceship::UserSpaceship()
  : Spaceship()
{
  alive = true;
}

UserSpaceship::~UserSpaceship()
{

}

UserSpaceship::UserSpaceship(int posx, int posy)
  : Spaceship(charUser, posx, posy)
{
  alive = true;
}

// Once UserSpaceship is a concrete class that inherit from abstract classes,
// UserSpaceship must implement the pure virtual functions declared in the base classes.
char UserSpaceship::getClass(void) {
  return getCharIcon();
}

/*
 * Implements the user's movimentation based on the user's input.
 * User moving to left -> decrements it's ypos value;
 * User moving to right -> increments it's ypos value;
 */
void UserSpaceship::move(int direction) {
  pair<int, int> position = getPosition();

  switch(direction) {
    case LEFT:
      position.second--;
    break;

    case RIGHT:
      position.second++;
    break;

    case UP:
      position.first--;
    break;

    case DOWN:
      position.first++;
    break;
  }

  setPosition(position);
}

// Once UserSpaceship is a concrete class that inherit from abstract classes,
// UserSpaceship must implement the pure virtual functions declared in the base classes.
Shot * UserSpaceship::shoot(void) {

  return NULL;
}

bool UserSpaceship::isAlive(void) {
  return alive;
}

void UserSpaceship::setDead(void) {
  alive = false;
}
