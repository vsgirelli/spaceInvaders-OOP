#include "barrier.h"

using namespace std;

Barrier::Barrier() {

}

Barrier::~Barrier() {

}

Barrier::Barrier(int pos) {
  charDef = charBarrier;
  position = pos;
  status = 1;
}
