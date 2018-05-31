#include <iostream>
#include <fstream> // used for FILE operations
#include <cstdlib> // used for system calls
#include <vector>
#include <string>

using namespace std;

// MENU SETTINGS
#define MAX_COLUMNS 61
#define MAX_LINES 31
#define MENU_TXT "./files/menu.txt"


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


// GAME
// quantidade de linhas de aiens
// quantidade de colunas de aliens
// etc
#define MAP_TXT "./files/map.txt"
#define charSpaceship '@'
#define charBarrier '#'
