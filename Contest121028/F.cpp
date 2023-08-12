// 数据很弱

#include <bits/stdc++.h>
using namespace std;

char a[500][500];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, ans = 0, r, c, N, M;

vector<pair<int, int>> Fs, Ms;

void check(char ch, const vector<pair<int, int>> &rabbits) {
  for (auto f : rabbits) {
    int x = f.first, y = f.second, count = 0;
    for (int i = 0; i < 4; i++) {
      int t = 1, xx, yy;
      bool f = true;
      do {
        xx = x + dx[i] * t, yy = y + dy[i] * t;
        if (a[xx][yy] == ch) {
          f = false;
          break;
        }
        t++;
      } while (xx >= 0 && xx < r && yy >= 0 && yy < c);
      count += f;
    }
    ans += count >= 3;
  }
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> r >> c >> N >> M;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'F') Fs.push_back({i, j});
      else if (a[i][j] == 'M') Ms.push_back({i, j});
    }
    getchar();
  }
  check('M', Fs);
  check('F', Ms);
  cout << ans;
  return 0;
}