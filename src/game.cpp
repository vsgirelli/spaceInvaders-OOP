#include "game.h"
#include <cstring>

using namespace std;

Game::Game() {
  loadMap();
}

Game::~Game() {

}

/*
 * Reads a .txt with the map
 */
void Game::loadMap() {
  /*
   * Manipulating files is easier with strings,
   * so we copy an entire line to a string and then
   * we copy the string to a line of the map matrix
   */
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

/*
 * Prepares the game by loading the spaceships,
 * the barriers and the status bar and calls the mainLoop()
 */
void Game::startGame(void) {
  loadSpaceships();
  loadBarriers();
  //loadStatusBar();
  mainLoop();
}

void Game::printGame(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    cout << map[i] << endl;
    }
}

/*
 * TODO atualizar descrição da mainLoop
 */
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

/*
 * For each occurrence of '@' in the map matrix
 * is istantiated a Spaceship object.
 */
void Game::loadSpaceships(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    for (int j = 0; j < MAX_COLUMNS; j++) {
      if (map[i][j] == charSpaceship) {
        spaceships.push_back(new Spaceship(i));
      }
    }
  }
}

/*
 * For each occurrence of '#' in the map matrix
 * is istantiated a Barrier object.
 */
void Game::loadBarriers(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    for (int j = 0; j < MAX_COLUMNS; j++) {
      if (map[i][j] == charBarrier) {
        barriers.push_back(new Barrier(i));
      }
    }
  }
}
