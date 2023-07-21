#include <bits/stdc++.h>
using namespace std;

int blanket[1001][1001];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      blanket[i][j] = 0;
  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    for (int x = x1; x <= x2; x++)
      for (int y = y1; y <= y2; y++)
        blanket[x][y]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << blanket[i][j] << ' ';
    cout << endl;
  }
  return 0;
}