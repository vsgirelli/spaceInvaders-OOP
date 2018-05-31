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

void Menu::mainLoop(void) {
  char keyPressed = '\0';
  do {
    printMenu();
    keyPressed = cin.get();
  } while(keyPressed != ENTER && keyPressed != ESC);
  
  if (keyPressed == ENTER) {
    game.startGame();
  }
  else if(keyPressed == ESC) {
    //cout << "termina jogo" << endl;
  }
}

void Menu::loadMenu(void) {
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

