#include <bits/stdc++.h>
using namespace std;

int square[121][121];

int main() {
  int n, maxn = -1 << 30;
  cin >> n;
  for (int i = 1; i <= n; i++)
    memset(square[i], 0, sizeof(square[i]));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> square[i][j];
      square[i][j] += square[i-1][j] + square[i][j-1] - square[i-1][j-1];
    }
  }
  for (int x1 = 1; x1 <= n; x1++) {
    for (int y1 = 1; y1 <= n; y1++) {
      for (int x2 = x1; x2 <= n; x2++) {
        for (int y2 = y1; y2 <= n; y2++) {
          maxn = max(maxn, square[x2][y2] + square[x1-1][y1-1] - square[x1-1][y2] - square[x2][y1-1]);
        }
      }
    }
  }
  cout << maxn;
  return 0;
}