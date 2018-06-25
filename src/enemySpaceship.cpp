#include "enemySpaceship.h"

using namespace std;

EnemySpaceship::EnemySpaceship()
  : Spaceship()
{

}

EnemySpaceship::~EnemySpaceship()
{

}

EnemySpaceship::EnemySpaceship(int posx, int posy, int dir)
  : Spaceship(charEnemy, posx, posy)
{
  direction = dir;
}

// Once EnemySpaceship is a concrete class that inherit from abstract classes,
// EnemySpaceship  must implement the pure virtual functions declared in the base classes.
char EnemySpaceship::getClass(void) {
  return getCharIcon();
}

void EnemySpaceship::move(int direction) {

}

void EnemySpaceship::shoot(void) {

}
