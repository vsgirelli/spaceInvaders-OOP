#include "game.h"

using namespace std;

Game::Game() {
  loadMap();
}

Game::~Game() {
  // deve deletar os objetos criados nos vectors
  // então quando o destrutor é chamado, deve-se
  // garantir que os detrutores de tudo tbm são chamados
  // isso faz com que o tipo de relação (pro UML)
  // deva ser uma composição
  // fazer as destroy pra tudo que foi load
}

/*
 * Reads a .txt with the map
 */
void Game::loadMap() {
  /*
   * Manipulating files is easier with strings,
   * so we copy an entire line to a string and then
   * we copy the string to a line of the auxMap matrix
   */
  string aux;
  ifstream arq;
  arq.open(MAP_TXT);

  if (arq.is_open()) {
    int i = 0;
    while (getline(arq, aux)) {
      aux.copy(auxMap[i], MAX_COLUMNS - 1, 0);
      auxMap[i][MAX_COLUMNS - 1] = '\0';
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
 * Prepares the game by loading the enemies spaceships,
 * the barriers and the status bar and calls the mainLoop()
 */
void Game::startGame(void) {
  clearMap();
  loadSpaceships();
  loadBarriers();
  //loadStatusBar();
  loadPlayer();
  mainLoop();
}

void Game::loadPlayer(void) {
  user = new UserSpaceship(MAX_COLUMNS / 2, MAX_LINES - 1);
}

// vai ser passada pra a classe display
void Game::printGame(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    cout << map[i] << endl;
  }
}

/*
* For each occurrence of '@' in the map matrix
* is istantiated a Spaceship object.
*/
void Game::loadSpaceships(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    for (int j = 0; j < MAX_COLUMNS; j++) {
      if (map[i][j] == charEnemy) {
        enemies.push_back(new EnemySpaceship(i, j, MOVE_RIGHT));
        //FIXME
        map[i][j] = ' ';
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
        barriers.push_back(new Barrier(i, j));
        //FIXME
        map[i][j] = ' ';
      }
    }
  }
}

/*
 * TODO atualizar descrição da mainLoop
 */
void Game::mainLoop(void) {
  char keyPressed = '\0';
  clock_t endFrameTime;

  do {
    while(!kbhit()) {
      clearMap();
      updatePositions();
      printGame();
      endFrameTime = clock(); // gets the current time

      waitClock(endFrameTime);
    }
    keyPressed = getchar();
    cout << "key: " << keyPressed << endl;
    updateUserPosition(RIGHT);

  } while(keyPressed != QUIT && keyPressed != quit);

  if(keyPressed == QUIT || keyPressed == quit) {
    cout << "termina jogo" << endl;
  }
}

void Game::clearMap(void) {
  clearScreen();
  resetMap();
}

void Game::resetMap(void) {
  for (int i = 0; i < MAX_LINES; i++) {
        for(int j = 0; j < MAX_COLUMNS; j++)
            map[i][j] = auxMap[i][j];
    }
}

/*
 *
 *
 */
void Game::updateUserPosition(int direction) {
  user->move(direction);
}

int Game::updatePositions(void) {

  return 0;
}
