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
  clearScreen();
  loadSpaceships();
  loadBarriers();
  //loadStatusBar();
  mainLoop();
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

/*
 * TODO atualizar descrição da mainLoop
 */
void Game::mainLoop(void) {
  char keyPressed = '\0';
  clock_t endFrameTime;

  do {
    //keyPressed = cin.get(); // used for user movements and game options
    // tem que ser como callback
    // senão fica travado esperando user apertar tecla
    updatePositions();
    clearScreen();
    printGame(); // depois vai ser chamada como display.print()
    endFrameTime = clock(); // gets the current time
    
    

    user.move();
    for(int i = 0; i < barriers.size(); i++) {
      spaceships.move();
    }

    // Faz o mesmo com as outras listas
    
    waitClock(endFrameTime);
  } while(keyPressed != QUIT && keyPressed != quit);

  if(keyPressed == QUIT || keyPressed == quit) {
    cout << "termina jogo" << endl;
  }
}

void Game::clearScreen()
{
  /*
   * A string of special characters
   * that translate to clear the screen command
   * and works for both Windows and Linux
   */
  cout << "\033[2J\033[1;1H";
}

/*
 *
 *
 */
int Game::updatePositions(){

  //checkBulletColisions();

  return 0;
}

/*
 * Executes until the clock reaches 600 milissenconds
 * and then returns the control to mainLoop()
 */
void Game::waitClock(clock_t endFrameTime){
  clock_t actualTime, deltaTime = 0;
  do {
    actualTime = clock();
    deltaTime = actualTime - endFrameTime;
  } while(clockToMilliseconds(deltaTime) < 600.0);
}

double Game::clockToMilliseconds(clock_t ticks){
    // units/(units/time) => time (seconds) * 1000 = milliseconds
    return (ticks/(double)CLOCKS_PER_SEC)*1000.0;
}
