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
#define MAX_LINES 31
#define MENU_TXT "./files/menu.txt"
#define MAP_TXT "./files/map.txt"


// KEYS
// informar o user de que ele precisa pressionar Q/q para sair
// pq é difícil capturar o ESC
#define ESC 27
#define ENTER '\n'
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
#define SPACE 32
#define quit 113
#define QUIT 81


// GAME
#define charEnemy '@'
#define charBarrier '#'
#define charUser '&'
#define charShot '|'
#define MOVE_RIGHT 1
#define MOVE_LEFT 2
#define MOVE_UPWARD 3
#define MOVW_DOWNWARD 4
