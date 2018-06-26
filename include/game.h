#include "enemySpaceship.h"
#include "userSpaceship.h"
#include "shot.h"
#include "barrier.h"
#include "config.h"
#include "utils.h"

using namespace std;

class Game
{
  private:
    char map[MAX_LINES][MAX_COLUMNS];     // map matrix read from a .txt
    char auxMap[MAX_LINES][MAX_COLUMNS];  // map matrix read from a .txt
    vector<EnemySpaceship*> enemies;      // enemies spaceships from the map
    vector<Barrier*> barriers;            // barriers from the map
    //StatusBar statusBar;                // status bar of the game
    UserSpaceship *user;                  // user spaceship


  public:
    Game();
    ~Game();
    void startGame(void);

  private:
    void loadMap(void);
    void printGame(void);
    void loadSpaceships(void);
    void loadBarriers(void);
    void loadPlayer(void);
    void mainLoop(void);
    void clearMap(void);
    void resetMap(void);
    void fillMap(void);
    //void loadStatusBar(void);
    void updateUserPosition(int direction);
    int updatePositions(void);
    //void checkBulletColisions(void); // percorre o vetor de tiros e checa
    //template <typename T> void killObject(T *obj); // destrói objeto atingido por um tiro
    //void endGame(void);
};
