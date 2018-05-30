#include "game.h"

using namespace std;

Game::Game() {
  loadMap();
  loadSpaceships();
}

Game::~Game() {

}

void Game::loadMap() {
  ifstream arq;
  arq.open(MAP_TXT);

  if (arq.is_open()) {
    int i = 0;
    while (getline(arq, map[i])) {
      i++;
    }
    arq.close();
  }
  else {
    cout << "Could not open file " << MAP_TXT << endl;
    exit(1);
  }
}

void Game::startGame(void) {
  mainLoop();
}

void Game::printGame(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    cout << map[i] << endl;
  }
}

void Game::mainLoop(void) {
  char keyPressed = '\0';
  do {
    printGame();
    keyPressed = cin.get();
  } while(keyPressed != ESC);

  if(keyPressed == ESC) {
    cout << "termina jogo" << endl;
  }
}

void Game::loadSpaceships(void) {
  // reads the map matrix and finds the positions
  // of the spaceships in it.
  // then, with the positions, calls the constructors
  // for the spaceships providing the position they should
  // be printed into de map matrix

}
