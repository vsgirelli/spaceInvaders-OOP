#include "game.h"
#include <cstring>

using namespace std;

Game::Game() {
  cout << __func__ << endl;
  loadMap();
}

Game::~Game() {

}

void Game::loadMap() {
  string aux;
  ifstream arq;
  arq.open(MAP_TXT);

  if (arq.is_open()) {
    int i = 0;
    while (getline(arq, aux)) {
      aux.copy(map[i], MAX_COLUMNS - 1, 0);
      map[i][MAX_COLUMNS - 1] = '\0';
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
  loadSpaceships();
  do {
    printGame();
    keyPressed = cin.get();
  } while(keyPressed != ESC);

  if(keyPressed == ESC) {
    cout << "termina jogo" << endl;
  }
}

void Game::loadSpaceships(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    for (int j = 0; j < MAX_COLUMNS; j++) {
      if (map[i][j] == charSpaceship) {
        spaceships.push_back(new Spaceship(i));
      }
    }
  }
  cout << "vector size: " << spaceships.size() << endl;
}
