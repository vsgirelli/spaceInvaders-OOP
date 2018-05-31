#include "spaceship.h"
#include "barrier.h"
#include "config.h"

using namespace std;

class Game 
{
  private:
    char map[MAX_LINES][MAX_COLUMNS];
    vector<Spaceship*> spaceships;
    vector<Barrier*> barriers;

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
