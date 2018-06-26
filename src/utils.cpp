#include "utils.h"

/*
 * Used to verify if the user pressed a key  
 */
int kbhit(void) {
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    // if pressed, returns 1
    return 1;
  }

  // if not pressed, returns 0
  return 0;
}

/*
 * Executes until the clock reaches TODO X milissenconds
 * and then returns the control to mainLoop()
 */
void waitClock(clock_t endFrameTime) {
  clock_t actualTime, deltaTime = 0;
  do {
    actualTime = clock();
    deltaTime = actualTime - endFrameTime;
  } while(clockToMilliseconds(deltaTime) < 600.0);
}

double clockToMilliseconds(clock_t ticks) {
    // units/(units/time) => time (seconds) * 1000 = milliseconds
    return (ticks/(double)CLOCKS_PER_SEC)*1000.0;
}

void clearScreen() {
  /*
   * A string of special characters
   * that translate to clear the screen command
   * and works for both Windows and Linux
   */
  cout << "\033[2J\033[1;1H";
}
