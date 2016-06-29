#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <vector>

using namespace std;

class Sudoku {
public:
  Sudoku(const vector<vector<int>>& table);
  void Solve();
  void Show() const;

private:
  void Solve(const int y, const int x);
  inline bool isValidNumber(const int checkNumber, const int y, const int x) const;
  inline int getBoxNumber(const int y, const int x) const;
  inline void setNumeber(const int setNumber, const int y, const int x);
  inline void unSetNumber(const int unSetNumber, const int y, const int x);

  vector<vector<int>> _table;
  vector<vector<bool>> _row, _col, _box;
  int _solved;
};

#endif SUDOKU_H_
