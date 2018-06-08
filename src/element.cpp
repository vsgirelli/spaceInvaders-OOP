#include "element.h"

using namespace std;

Element::Element() {

};

Element::~Element() {

}

Element::Element(char def, int posx, int posy) {
  charDef = def;
  xpos = posx;
  ypos = posy;
}

bool Element::isColliding(Element *element) {

}

char Element::getCharDef(void) {
  return charDef;
}

pair<int, int> Element::getPosition(void) {
  return make_pair(xpos, ypos);
}

void Element::setPosition(int posx, int posy) {
  xpos = posx;
  ypos = posy;
}
