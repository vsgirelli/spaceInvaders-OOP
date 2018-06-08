#include "element.h"

using namespace std;

Element::Element() {

};

Element::~Element() {

}

Element::Element(char def, int posx, int posy) {
  this.charDef = def;
  this.xpos = posx;
  this.ypos = posy;
}

bool Element::isColliding(Element *element) {

}
/*
char Element::getCharDef(void) {
  return this.charDef;
}

void Element::setCharDef(char def) {
  this.charDef = def;
}
*/
pair<int, int> Element::getPosition(void) {
  return make_pair(this.xpos, this.ypos);
}

void Element::setPosition(int posx, int posy) {
  this.xpos = posx;
  this.ypos = posy;
}
