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
    char map[MAX_LINES][MAX_COLUMNS];           // map matrix read from a .txt
    char originalMap[MAX_LINES][MAX_COLUMNS];   // map matrix read from a .txt
    vector<EnemySpaceship*> enemies;            // enemies spaceships from the map
    vector<Barrier*> barriers;                  // barriers from the map
    vector<Shot*> projectiles;                  // bullets from the map
    //StatusBar statusBar;                      // status bar of the game
    UserSpaceship *user;                        // user spaceship

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
    int mainLoop(void);
    void clearMap(void);
    void resetMap(void);
    void loadStatusBar(void);
    void fillMap(void);
    void updateUserAction(char action); //TODO VAL UML
    void updatePositions(void);
    void updateEnemies(void);
    void updateShots(void);
    void checkCollision(Shot* shot); //TODO VAL UML
    void endGame(int result);
    template <typename T> void killObject(vector<T*> vecObj); // TODO VAL UML
};
