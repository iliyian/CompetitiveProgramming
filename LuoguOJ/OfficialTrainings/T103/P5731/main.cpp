#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int n;

array<int, 4> dx{0, 1, 0, -1};
array<int, 4> dy{1, 0, -1, 0};
array<array<int, 9>, 9> square{};

bool inRange(const int &x, const int &y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

int x = 0, y = 0, d = 0;

void step() {
  int x2 = x + dx[d], y2 = y + dy[d];
  if (!inRange(x2, y2) || square[x2][y2]) {
    d = (d + 1) % 4;
    step();
  }
  else x = x2, y = y2;
}

int main() {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    square[x][y] = i + 1;
    if (i != n * n - 1) step();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << setw(3) << setfill(' ') << square[i][j];
    cout << endl;
  }
  return 0;
}