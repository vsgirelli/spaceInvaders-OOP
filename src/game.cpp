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
  mainLoop();
}

void Game::loadPlayer(void) {
  user = new UserSpaceship(MAX_COLUMNS / 2, MAX_LINES - 1);
  pair<int, int> pos = user->getPosition();
  cout << "x: " << pos.first << " y: " << pos.second << endl;
}

// vai ser passada pra a classe display
void Game::printGame(void) {
  for (int i = 0; i < MAX_LINES; i++) {
    cout << map[i] << endl;
  }
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
void Game::mainLoop(void) {
  char keyPressed = '\0';
  clock_t endFrameTime;

  do {
    // while user does not press any key
    while(!kbhit()) {
      clearMap();
      updatePositions();
      printGame();

      endFrameTime = clock(); // gets the current time
      waitClock(endFrameTime);
    }

    // if kbhit returns 1, means that the user pressed a key
    keyPressed = getchar();
    updateUserPosition(keyPressed);

  } while(keyPressed != ESC);

  if(keyPressed == ESC) {
    cout << "termina jogo" << endl;
  }
}

/*
 * Clears the screen and the map matrix
 */
void Game::clearMap(void) {
  clearScreen();
  resetMap();
}

/*
 * Clears the map to later fill with the new positions
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

  for (int i = 0; i < (int) projectiles.size(); i++) {
    position = projectiles[i]->getPosition();
    icon = projectiles[i]->getCharIcon();
    map[position.second][position.first] = icon;
  }

  for (int i = 0; i < (int) barriers.size(); i++) {
    position = barriers[i]->getPosition();
    icon = barriers[i]->getCharIcon();
    map[position.second][position.first] = icon;
  }

}

void Game::updateUserPosition(int direction) {
  user->move(direction);
}


void Game::updateShots() {
  srand (time(NULL));
  int j = 0;

  //Gerar randomicamente com supostos 40% de chance um tiro randomico a cada iteracao
  if ((rand() % 100 < 40 && (int) enemies.size())) {
    int randomEnemy = rand() % (int) enemies.size();
    projectiles.push_back(enemies[randomEnemy]->shoot());
  }

  //Mover todos os projetes e testar colisao e que nao passe do chao
  for (int i = 0; i < (int) projectiles.size(); i++) {
    projectiles[j]->move();
    if (projectiles[j]->getPosition().second > MAX_LINES-2) {
      //TODO arrumar isso pq ele n sabe direito como chamar delete por ser polimorfico
      delete projectiles[j];
      projectiles.erase(projectiles.begin() + j);
      j--;
    }
    else
    {
      //TODO
      //checkCollision()
    }
    j++;
  }
}

/*
 *  Updates positions of enemies and shots on the map on each clock.
 */
void Game::updatePositions(void) {
  updateEnemies();
  updateShots();
  fillMap();
}

/*
 * Updates the enemie's position based on the current class direction
 * and on the current class directionSteps.
 */
void Game::updateEnemies(void){
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
    }
  }
}
