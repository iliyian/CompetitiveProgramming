#include <iostream>
#include <array>
#include <cmath>
using namespace std;

int n;

bool inRange(const int &x, const int &y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
  int m, k;
  cin >> n >> m >> k;
  array<array<int, 100>, 100> square{};

  while (m--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (square[x][y] < 0) continue;
    for (int i = -1; i <= 1; i++)
      for (int j = -1; j <= 1; j++) {
        int x2 = x + i, y2 = y + j;
        if (inRange(x2, y2) && !square[x2][y2])
          square[x2][y2] = 1;
      }
    square[x-2][y] = square[x+2][y] = square[x][y-2] = square[x][y+2] = 1;
    square[x][y] = -1;
  }
  while (k--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (square[x][y] < 0) continue;
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int x2 = x + i, y2 = y + j;
        if (inRange(x2, y2) && !square[x2][y2])
          square[x2][y2] = 1;
      }
    }
    square[x][y] = -1;
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      ans += !square[i][j];
  }

  cout << ans;
  return 0;
}