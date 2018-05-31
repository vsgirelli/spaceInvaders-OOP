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
    char menu[MAX_LINES][MAX_COLUMNS];  // menu matrix read from a .txt

  public:
    Menu();
    ~Menu();
    void startMenu(void);

  private:
    void mainLoop(void);
    void loadMenu(void);
    void printMenu(void);

};
