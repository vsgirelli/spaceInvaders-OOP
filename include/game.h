#include "spaceship.h"
#include "barrier.h"
#include "config.h"

using namespace std;

class Game
{
  private:
    char map[MAX_LINES][MAX_COLUMNS];   // map matrix read from a .txt
    vector<EnemySpaceship*> spaceships; // spaceships from the map
    vector<Barrier*> barriers;          // barriers from the map
    //StatusBar statusBar;              // status bar of the game
    //UserSpaceship user;               // user spaceship

  public:
    Game();
    ~Game();
    void startGame(void);

  private:
    void loadMap(void);
    void printGame(void);
    void loadSpaceships(void);
    void loadBarriers(void);
    void mainLoop(void);
    //void loadStatusBar(void);
    int updatePositions(void);
    //void checkBulletColisions(void); // percorre o vetor de tiros e checa
    void waitClock(clock_t endFrameTime);
    double clockToMilliseconds(clock_t ticks);
    //template <typename T> void killObject(T *obj); // destrói objeto atingido por um tiro
    //void endGame(void);
    void clearScreen(void);

};
