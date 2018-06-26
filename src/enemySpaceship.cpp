#include "enemySpaceship.h"

using namespace std;

EnemySpaceship::EnemySpaceship()
  : Spaceship()
{

}

EnemySpaceship::~EnemySpaceship()
{

}

EnemySpaceship::EnemySpaceship(int posx, int posy)
  : Spaceship(charEnemy, posx, posy)
{
}

// Once EnemySpaceship is a concrete class that inherit from abstract classes,
// EnemySpaceship must implement the pure virtual functions declared in the base classes.
char EnemySpaceship::getClass(void) {
  return getCharIcon();
}

void EnemySpaceship::move(int direction) {

  pair<int,int> position = getPosition();
  switch (direction) {

    case MOVE_RIGHT:
      position.first +=1;
    break;

    case MOVE_LEFT:
      position.first -=1;
    break;

    case MOVE_UPWARD:
    position.second -=1;
    break;

    case MOVE_DOWNWARD:
    position.second +=1;
    break;
  }

  setPosition(position);

}

void EnemySpaceship::shoot(void) {

}
