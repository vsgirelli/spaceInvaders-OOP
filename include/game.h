#include <iostream>
#include <fstream> // used for FILE operations
#include <cstdlib> // used for system calls
#include "config.h"

using namespace std;

class Game 
{
  private:
    string map[MAX_LINES];

  public:
    Game();
    ~Game();
    void startGame(void);

  private:
    void loadMap(void);
    void printGame(void);
};
