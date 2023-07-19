#include <bits/stdc++.h>
using namespace std;

array<array<int, 30>, 30> arr;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n;

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int x0 = dx[i] + x, y0 = dy[i] + y;
    if (x0 >= 0 && x0 < n && y0 >= 0 && y0 < n && arr[x0][y0] == 0) {
      arr[x0][y0] = -1;
      dfs(x0, y0);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  for (int i = 0; i < n; i++) {
    if (!arr[i][0])
      dfs(i, 0);
    if (!arr[i][n - 1])
      dfs(i, n -1);
    if (!arr[0][i])
      dfs(0, i);
    if (!arr[n - 1][i])
      dfs(n - 1, i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] < 0) cout << 0;
      if (arr[i][j] == 1) cout << 1;
      if (arr[i][j] == 0) cout << 2;
      cout << " ";
    }
    cout << endl;
  }
  return 0;
}