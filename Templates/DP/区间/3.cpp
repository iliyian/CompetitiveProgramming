#include <bits/stdc++.h>
using namespace std;

bool can[4][4][4], f[201][201][4];

map<char, int> m = {
  {'W', 0},
  {'I', 1},
  {'N', 2},
  {'G', 3},
};
char mm[] = {'W', 'I', 'N', 'G'};

int t[4];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int w, i, g;
  cin >> t[0] >> t[1] >> t[2] >> t[3];
  memset(can, 0, sizeof(can));
  memset(f, 0, sizeof(f));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < t[i]; j++) {
      string str;
      cin >> str;
      can[i][m[str[0]]][m[str[1]]] = true;
    }
  }
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    f[i + 1][i + 1][m[str[i]]] = true;
  }
  int n = str.size();
  for (int len = 2; len <= n; len++) {
    // 区间 dp 最外层必须是 len
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        for (int c = 0; c < 4; c++)
          for (int c1 = 0; c1 < 4; c1++)
            for (int c2 = 0; c2 < 4; c2++) {
              if (can[c][c1][c2] && f[i][k][c1] && f[k + 1][j][c2])
                f[i][j][c] = true;
            }
      }
    }
  }
  bool F = false;
  for (int i = 0; i < 4; i++) {
    if (f[1][n][i])
      cout << mm[i], F = true;
  }
  if (!F)
    cout << "The name is wrong!";
  return 0;
}