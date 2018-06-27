#include "element.h"

using namespace std;

Element::Element() {

};

Element::~Element() {

}

Element::Element(char def, int posx, int posy) {
  charIcon = def;
  xpos = posx;
  ypos = posy;
}

bool Element::isColliding(Element *element) {
  if (getPosition().first == element->getPosition().first && getPosition().second == element->getPosition().second) {
    return true;
  }
  return false;
}

char Element::getCharIcon(void) {
  return charIcon;
}

pair<int, int> Element::getPosition(void) {
  return make_pair(xpos, ypos);
}

void Element::setPosition(pair<int, int> position) {
  xpos = position.first;
  ypos = position.second;
}
