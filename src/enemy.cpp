#include "spaceship.h"

using namespace std;

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

Enemy::Enemy(int pos) {
  charDef = charEnemy;
  position = pos;
  status = true;
}
