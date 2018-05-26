#include <iostream>
#include <fstream> // used for FILE operations
#include <cstdlib> // used for system calls
#include "config.h"

using namespace std;

class Menu
{
  private:
    //Game game;
    //http://www.cplusplus.com/reference/chrono/steady_clock/
    //http://www.cplusplus.com/reference/chrono/
    //https://stackoverflow.com/questions/409348/iteration-over-stdvector-unsigned-vs-signed-index-variable
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
