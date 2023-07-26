#include <bits/stdc++.h>
using namespace std;

int n, h, w;
int tuteng[1100][2100];

void draw(int size, int x, int y) {
  if (size == 1) {
    tuteng[x][y] = tuteng[x - 1][y + 1] = '/';
    tuteng[x][y + 1] = tuteng[x][y + 2] = '_';
    tuteng[x][y + 3] = tuteng[x - 1][y + 2] = '\\';
    return;
  }
  draw(size - 1, x, y);
  draw(size - 1, x, y + pow(2, size));
  draw(size - 1, x - pow(2, size - 1), y + pow(2, size - 1));
}

int main() {
  cin >> n;
  h = pow(2, n);
  w = h * 2;
  draw(n, h - 1, 0);

  for (int i = 0; i < h; i++) {
    int maxw;
    for (int j = w - 1; j >= 0; j--)
      if (tuteng[i][j]) {
        maxw = j; break;
      }
    for (int j = 0; j <= maxw; j++) {
      cout << char(tuteng[i][j] ? tuteng[i][j] : ' ');
    }
    cout << '\n';
  }

  return 0;
}