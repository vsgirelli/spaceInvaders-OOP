#include "barrier.h"

using namespace std;

Barrier::Barrier()
  : Element()
{

}

Barrier::~Barrier() {

}

Barrier::Barrier(int posx, int posy)
  : Element(charBarrier, posx, posy)
{

}

char Barrier::getClass(void) {
  return this.charDef;
}
