#include "menu.h"

using namespace std;

Menu::Menu() {
  loadMenu();
}

Menu::~Menu() {

}

void Menu::startMenu(void) {
  mainLoop();
}

/*
 * Loop that keeps executing until the user presses
 * a specific key and then calls the handler
 */
void Menu::mainLoop(void) {
  char keyPressed = '\0';
  do {
    printMenu();
    keyPressed = cin.get();
  } while(keyPressed != ENTER && keyPressed != QUIT && keyPressed != quit);
  
  if (keyPressed == ENTER) {
    game.startGame();
  }
  else if(keyPressed == QUIT || keyPressed == quit) {
    //cout << "termina jogo" << endl;
  }
}

/*
 * Reads a .txt with the menu
 */
void Menu::loadMenu(void) {
  /*
   * Manipulating files is easier with strings,
   * so we copy an entire line to a string and then
   * we copy the string to a line of the menu matrix
   */
  string aux;
  ifstream arq;
  arq.open(MENU_TXT);
  
  if (arq.is_open()) {
    int i = 0;
    while (getline(arq, aux)) {
      aux.copy(menu[i], MAX_COLUMNS - 1, 0);
      menu[i][MAX_COLUMNS - 1] = '\0';
      i++;
    }
    arq.close();
  }
  else {
    cout << "Could not open file " << MENU_TXT << endl;
    exit(1);
  }
}

void Menu::printMenu(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    puts(menu[i]);
  }
}

