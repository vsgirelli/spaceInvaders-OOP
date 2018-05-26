#include "menu.h"

using namespace std;

Menu::Menu() {
  readMenuFile();
}

Menu::~Menu() {

}

void Menu::startMenu(void) {
  mainLoop();
}

void Menu::mainLoop(void) {
  char keyPressed;
  do {
    printMenu();
    keyPressed = cin.get();
  } while(keyPressed != ENTER && keyPressed != ESC);
  
  if (keyPressed == ENTER) {
    //game.startGame();
  }
  else if(keyPressed == ESC) {
    //cout << "termina jogo" << endl;
  }
}

void Menu::readMenuFile(void) {
  ifstream arq;
  arq.open(MENU_TXT);
  
  if (arq.is_open()) {
    int i = 0;
    while (getline(arq, menu[i])) {
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
    cout << menu[i] << endl;
  }
}

