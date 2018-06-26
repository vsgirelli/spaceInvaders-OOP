#include <iostream>
#include <fstream> // used for FILE operations
#include <cstdlib> // used for system calls
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <utility>
#include <functional>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

// FILES SETTINGS
#define MAX_COLUMNS 61
#define MAX_LINES 30
#define MENU_TXT "./files/menu.txt"
#define MAP_TXT "./files/map.txt"


// KEYS
// informar o user de que ele precisa pressionar Q/q para sair
// pq é difícil capturar o ESC
#define ESC 27
#define ENTER '\n'
#define RIGHT 68  // D
#define LEFT 65   // A
#define UP 87     // W
#define DOWN 83   // S
#define right 100 // d
#define left 97   // a
#define up 119    // w
#define down 115  // s
#define SPACE 32
#define quit 113  // Q
#define QUIT 81   // q


// GAME
#define charEnemy '@'
#define charBarrier '#'
#define charUser '&'
#define charShot '|'
#define MOVE_RIGHT 1
#define MOVE_LEFT 2
#define MOVE_UPWARD 3
#define MOVE_DOWNWARD 4
#define LEFTSTEPS 17;
#define RIGHTSTEPS 17;
#define INITIALSTEPS 10;
#define DEAD 0
#define EXIT 1
