#include <iostream>
#include <fstream> // used for FILE operations
#include <cstdlib> // used for system calls
#include "config.h"
#include "game.h"

using namespace std;

class Menu
{
  private:
    Game game;
    //http://www.cplusplus.com/reference/chrono/steady_clock/
    //http://www.cplusplus.com/reference/chrono/
    //https://stackoverflow.com/questions/409348/iteration-over-stdvector-unsigned-vs-signed-index-variable
    char menu[MAX_LINES][MAX_COLUMNS];

  public:
    Menu();
    ~Menu();
    void startMenu(void);

  private:
    void mainLoop(void);
    void loadMenu(void);
    void printMenu(void);

};
