#include <iostream>
#include <fstream> // used for FILE operations
#include <cstdlib> // used for system calls
#include "config.h"

using namespace std;

class Menu
{
  private:
    //Game game;
    string menu[MAX_LINES];

  public:
    Menu();
    ~Menu();
    void startMenu(void);

  private:
    void mainLoop(void);
    void readMenuFile(void);
    void printMenu(void);

};
