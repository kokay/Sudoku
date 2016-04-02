#include <iostream>
#include <time.h>
#include "sudoku.h"

using namespace std;

int main() {
  Sudoku sudoku({
    { 0, 7, 0,  0, 3, 0,  0, 0, 8 },
    { 0, 0, 2,  0, 0, 0,  0, 1, 4 },
    { 1, 0, 8,  0, 0, 4,  7, 0, 0 },

    { 0, 8, 0,  0, 0, 5,  0, 0, 0 },
    { 0, 0, 7,  8, 1, 2,  9, 0, 0 },
    { 0, 0, 0,  4, 0, 0,  0, 8, 0 },

    { 0, 0, 5,  6, 0, 0,  3, 0, 9 },
    { 7, 2, 0,  0, 0, 0,  6, 0, 0 },
    { 6, 0, 0,  0, 4, 0,  0, 7, 0 },
  });

  sudoku.Show();
  cout << endl;

  clock_t time = clock();
  sudoku.Solve();
  time = clock() - time;

  sudoku.Show();
  cout << ((float)time) / CLOCKS_PER_SEC << endl;
}