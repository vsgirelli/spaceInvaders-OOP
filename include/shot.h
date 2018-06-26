#include "config.h"
#include "movingElement.h"

#pragma once

using namespace std;

class Shot: public MovingElement
{
  private:
    int direction;  // Direction to walk. 

  public:
    Shot();
    ~Shot();
    Shot(int posx, int posy, int dir);
    char getClass(void);
    void move(int direction);
    void move();
};
