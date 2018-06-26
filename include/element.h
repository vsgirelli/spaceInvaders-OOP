#include "config.h"

#pragma once

using namespace std;

// Abstract class inherited by all the interactive objects in the game.
class Element
{
  private:
    char charIcon; // character used to define the object in the map
    int xpos;      // position of the object in the map matrix
    int ypos;

  public:
    Element();
    ~Element();
    Element(char def, int posx, int posy);
    bool isColliding(Element *element);
    char getCharIcon(void);
    pair<int, int> getPosition(void);
    void setPosition(pair<int, int>);

    // A class is abstract if it has at least one pure virtual function,
    // which is a function that is only declared
    // and must be overridden by any concrete derived class.
    virtual char getClass(void) = 0;
};
