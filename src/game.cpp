#include "game.h"

using namespace std;

Game::Game() {
  loadMap();
  EnemySpaceship::direction = MOVE_RIGHT;
  EnemySpaceship::directionSteps = INITIALSTEPS;
}

Game::~Game() {
  // deve deletar os objetos criados nos vectors
  // então quando o destrutor é chamado, deve-se
  // garantir que os detrutores de tudo tbm são chamados
  // isso faz com que o tipo de relação (pro UML)
  // deva ser uma composição
  // fazer as destroy pra tudo que foi load
  for (int i = enemies.size() - 1; i >= 0; i--) {
    delete(enemies[i]);
  }
  enemies.erase(enemies.begin(), enemies.end());

  for (int i = barriers.size() - 1; i >= 0; i--) {
    delete(barriers[i]);
  }
  barriers.erase(barriers.begin(), barriers.end());

  delete(user);
}

/*
 * Reads a .txt with the map
 */
void Game::loadMap() {
  /*
   * Manipulating files is easier with strings,
   * so we copy an entire line to a string and then
   * we copy the string to a line of the originalMap matrix
   */
  string aux;
  ifstream arq;
  arq.open(MAP_TXT);

  if (arq.is_open()) {
    int i = 0;
    while (getline(arq, aux)) {
      aux.copy(originalMap[i], MAX_COLUMNS - 1, 0);
      originalMap[i][MAX_COLUMNS - 1] = '\0';
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
  loadStatusBar();
  loadPlayer();
  int ret = mainLoop();
  endGame(ret);
}

void Game::endGame(int result) {
  switch (result) {
    case DEAD:
      clearScreen();
    break;

    case EXIT:
      clearScreen();
    break;
  }
}

void Game::printGame(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    cout << map[i] << endl;
  }
}

void Game::loadPlayer(void) {
  user = new UserSpaceship(MAX_LINES - 2, MAX_COLUMNS / 2);
}

/*
 * For each occurrence of '@' in the originalMap matrix
 * is istantiated a Spaceship object.
 */
void Game::loadSpaceships(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    for (int j = 0; j < MAX_COLUMNS; j++) {
      if (map[i][j] == charEnemy) {
        enemies.push_back(new EnemySpaceship(j, i));
        originalMap[i][j] = ' ';
      }
    }
  }
}

/*
 * For each occurrence of '#' in the originalMap matrix
 * is istantiated a Barrier object.
 */
void Game::loadBarriers(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    for (int j = 0; j < MAX_COLUMNS; j++) {
      if (map[i][j] == charBarrier) {
        barriers.push_back(new Barrier(j, i));
        originalMap[i][j] = ' ';
      }
    }
  }
}

void Game::loadStatusBar(void) {

}

/*
 * TODO atualizar descrição da mainLoop
 */
int Game::mainLoop(void) {
  char keyPressed = '\0';
  clock_t endFrameTime;
  bool alive;

  do {
    // while user does not press any key and is still alive
    while(!kbhit() && user->isAlive()) {
      clearMap();
      updatePositions();
      printGame();

      endFrameTime = clock(); // gets the current time
      waitClock(endFrameTime);
    }

    if (!user->isAlive()) {
      break;
    }
    // if kbhit returns 1, means that the user pressed a key
    keyPressed = getchar();
    updateUserPosition(keyPressed);
  } while(keyPressed != ESC);

  if (!alive) {
    return DEAD;
  }
  else if (keyPressed == ESC) {
    return EXIT;
  }
}

/*
 * Clears the screen and the map matrix.
 */
void Game::clearMap(void) {
  clearScreen();
  resetMap();
}

/*
 * Clears the map to later fill with the new positions.
 */
void Game::resetMap(void) {
  for (int i = 0; i < MAX_LINES; i++) {
        for(int j = 0; j < MAX_COLUMNS; j++)
            map[i][j] = originalMap[i][j];
  }
}

/*
 *  Fills the map matrix with the new positions of the objects.
 */
void Game::fillMap(void) {
  pair<int,int> position;
  char icon;

  for (int i = 0; i < (int) enemies.size(); i++) {
    position = enemies[i]->getPosition();
    icon = enemies[i]->getCharIcon();
    map[position.second][position.first] = icon;
  }

  for (int i = 0; i < (int) barriers.size(); i++) {
    position = barriers[i]->getPosition();
    icon = barriers[i]->getCharIcon();
    map[position.second][position.first] = icon;
  }

  position = user->getPosition();
  icon = user->getCharIcon();
  map[position.first][position.second] = icon;
}

void Game::updateUserPosition(char direction) {
  if (direction == LEFT || direction == left) {
    user->move(LEFT);
  }
  else if (direction == RIGHT || direction == right) {
    user->move(RIGHT);
  }
  else if (direction == UP || direction == up) {
    user->move(UP);
  }
  else if (direction == DOWN || direction == down) {
    user->move(DOWN);
  }
}

/*
 *  Updates positions of enemies and shots on the map on each clock.
 */
void Game::updatePositions(void) {
  updateEnemies();
  //updateShots();
  fillMap();
}

/*
 * Updates the enemie's position based on the current class direction
 * and on the current class directionSteps.
 */
void Game::updateEnemies(void){
  pair<int, int> position;

  // If the enemies still can walk on the current direction,
  if (EnemySpaceship::directionSteps > 0) {
    // for each EnemySpaceship, call move.
    for (int i = 0; i < (int) enemies.size(); i++) {
      enemies[i]->move(EnemySpaceship::direction);
    }
    // Control the number of steps if each direction.
    EnemySpaceship::directionSteps -= 1;
  }

  // If the enemies can't walk on the current direction anymore,
  // then change it's direction and the current directionSteps available.
  else
  {
    if (EnemySpaceship::direction == MOVE_RIGHT) {
      EnemySpaceship::direction = MOVE_LEFT;
      EnemySpaceship::directionSteps = LEFTSTEPS;
    }
    else
    {
      EnemySpaceship::direction = MOVE_RIGHT;
      EnemySpaceship::directionSteps = RIGHTSTEPS;
    }

    // When the enemies reached the end of that direction/line,
    // they can go down one position.
    for (int i = 0; i < (int) enemies.size(); i++) {
      enemies[i]->move(MOVE_DOWNWARD);

      // If the enemies reach the bottom of the map,
      // the user dies.
      position = enemies[i]->getPosition();
      if (position.second >= MAX_LINES - 15) {
        user->setDead();
      }
    }
  }
}
