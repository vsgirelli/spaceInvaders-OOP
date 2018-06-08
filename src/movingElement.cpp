#include "movingElement.h"

using namespace std;

MovingElement::MovingElement()
  : Element()
{

}

MovingElement::~MovingElement() {

}

MovingElement::MovingElement(char def, int posx, int posy)
  : Element(def, posx, posy)
{

}
