#include "config.h"
#include "element.h"

using namespace std;

class Barrier : public Element
{
  public:
    Barrier();
    ~Barrier();
    Barrier(int posx, int posy);
    char getClass(void);
};
