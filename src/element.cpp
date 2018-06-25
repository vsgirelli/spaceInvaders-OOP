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
return true;
}

char Element::getCharIcon(void) {
  return charIcon;
}

pair<int, int> Element::getPosition(void) {
  return make_pair(xpos, ypos);
}

void Element::setPosition(int posx, int posy) {
  xpos = posx;
  ypos = posy;
}
