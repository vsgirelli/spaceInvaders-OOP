#include <iostream>
#include <fstream> // used for FILE operations
#include <cstdlib> // used for system calls
#include <vector>
#include "spaceship.h"
#include "config.h"

using namespace std;

class Game 
{
  private:
    string map[MAX_LINES];
    vector<Spaceship*> spaceships;

  public:
    Game();
    ~Game();
    void startGame(void);

  private:
    void loadMap(void);
    void printGame(void);
    void mainLoop(void);
    void loadSpaceships(void);
};
