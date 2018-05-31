#include "spaceship.h"
#include "barrier.h"
#include "config.h"

using namespace std;

class Game 
{
  private:
    char map[MAX_LINES][MAX_COLUMNS]; // map matrix read from a .txt
    vector<Spaceship*> spaceships;    // spaceships from the map
    vector<Barrier*> barriers;        // barriers from the map
    //StatusBar statusBar;              // status bar of the game

  public:
    Game();
    ~Game();
    void startGame(void);

  private:
    void loadMap(void);
    void printGame(void);
    void mainLoop(void);
    void loadSpaceships(void);
    void loadBarriers(void);
};
