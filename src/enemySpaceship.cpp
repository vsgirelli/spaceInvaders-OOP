#include "enemySpaceship.h"

using namespace std;

EnemySpaceship::EnemySpaceship()
  : Element()
{

}

EnemySpaceship::~EnemySpaceship()
{

}

EnemySpaceship::EnemySpaceship(int posx, int posy, int dir)
  : Element(charEnemy, posx, posy)
{
  this.direction = dir;
}

// Once EnemySpaceship is a concrete class that inherit from abstract classes,
// EnemySpaceship  must implement the pure virtual functions declared in the base classes.
char EnemySpaceship::getClass(void) {
  return this.charDef;
}

void EnemySpaceship::move(void) {

}

void EnemySpaceship::shoot(void) {

}
