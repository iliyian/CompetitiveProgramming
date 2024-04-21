#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  for (int i = 0; i < 8; i++) {
    bool getS = false, getC = false;
    int xx = x3 + dx[i], yy = y3 + dy[i];
    for (int j = 0; j < 8; j++) {
      int xxx = xx + dx[j], yyy = yy + dy[j];
      if (xxx == x1 && yyy == y1) getS = true;
      if (xxx == x2 && yyy == y2) getC = true;
    }
    if (getS && getC) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}