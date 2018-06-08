#include "barrier.h"

using namespace std;

Barrier::Barrier()
  : Element()
{

}

Barrier::~Barrier()
{

}

Barrier::Barrier(int posx, int posy)
  : Element(charBarrier, posx, posy)
{

}

// Once Barrier is a concrete class that inherit from abstract classes,
// Barrier must implement the pure virtual functions declared in the base classes.
char Barrier::getClass(void) {
  return this.charDef;
}
