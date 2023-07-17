#include <iostream>
#include <array>
using namespace std;

array<array<int, 100>, 100> rect;

int n, m;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool inRange(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m; 
}

void add(int x, int y) {
  for (int i = 0; i < 8; i++) {
    int x0 = x + dx[i], y0 = y + dy[i];
    if (inRange(x0, y0) && rect[x0][y0] >= 0)
      rect[x0][y0]++;
  }
}

int main() {
  cin >> n >> m;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      char ch = s[j];
      if (s[j] == '*') {
        rect[i][j] = -1;
        add(i, j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (rect[i][j] < 0) cout << '*';
      else cout << rect[i][j];
    }
    cout << endl;
  }
  return 0;
}