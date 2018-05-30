#include "game.h"

using namespace std;

Game::Game() {
  loadMap();
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
  // vai chamar a mainLoop
  // que vai printar o jogo e fazer funcionar
  // mas por enquanto só printa pra testar
  printGame();
}

void Game::printGame(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    cout << map[i] << endl;
  }
}
