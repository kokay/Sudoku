#include <vector>
#include <iostream>
#include "sudoku.h"

using namespace std;

Sudoku::Sudoku(const vector<vector<int>>& table)
  : _table(table)
  , _row(_table.size(), vector<bool>(_table.size() + 1, false))
  , _col(_table.size(), vector<bool>(_table.size() + 1, false))
  , _box(_table.size(), vector<bool>(_table.size() + 1, false))
  , _solved(0) {

  for (int y = 0;y < _table.size();++y) {
    for (int x = 0;x < _table[y].size();++x)
      if (_table[y][x] != 0)
        setNumeber(_table[y][x], y, x);
  }
}

void Sudoku::Solve() {
  Solve(0, 0);
}

void Sudoku::Show() const {
  cout << "+-----+-----+-----+" << endl;
  for (int y = 0;y < _table.size();++y) {
    cout << "|";
    for (int x = 0;x < _table[y].size();++x) {
      if (_table[y][x] == 0) cout << " ";
      else cout << _table[y][x];
      
      if (x % 3 == 2) cout << "|";
      else cout << " ";
    }
    cout << endl;
    if(y % 3 == 2) 
      cout << "+-----+-----+-----+" << endl;
  }
}

void Sudoku::Solve(const int y, const int x) {
  if (_solved == 81) return;
  
  int nextY = (x == 8)? y + 1 : y;
  int nextX = (x == 8)? 0 : x + 1;
  
  if (_table[y][x] != 0) {
    Solve(nextY, nextX);
  }
  else {
    for (int i = 1;i <= 9;++i) {
      if (!isValidNumber(i, y, x)) continue;
      
      setNumeber(i, y, x);
      Solve(nextY, nextX);
      if (_solved == 81) return;
      unSetNumber(i, y, x);
    }
  }
}

inline bool Sudoku::isValidNumber(const int checkNumber, const int y, const int x) const {
  if (_row[y][checkNumber] || _col[x][checkNumber] || _box[getBoxNumber(y, x)][checkNumber])
    return false;

  return true;
}

inline int Sudoku::getBoxNumber(const int y, const int x) const {
  return ((y / 3) * 3) + (x / 3);
}

inline void Sudoku::setNumeber(const int setNumber, const int y, const int x) {
  ++_solved;
  _table[y][x] = setNumber;
  _row[y][setNumber] = true;
  _col[x][setNumber] = true;
  _box[getBoxNumber(y, x)][setNumber] = true;
}

inline void Sudoku::unSetNumber(const int unSetNumber, const int y, const int x) {
  --_solved;
  _table[y][x] = 0;
  _row[y][unSetNumber] = false;
  _col[x][unSetNumber] = false;
  _box[getBoxNumber(y, x)][unSetNumber] = false;
}