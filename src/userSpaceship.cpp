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

void UserSpaceship::move(int direction) {
   if (direction == LEFT) {
     //ypos--;
   }
   else if (direction == RIGHT) {
     //ypos++;
   }
}

void UserSpaceship::shoot(void) {

  cout << "oi" << endl;
}
