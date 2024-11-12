#include <bits/stdc++.h>
#include <functional>
#define int long long
using namespace std;

constexpr int N = 300;

int f[N + 1][N + 1][N + 1][3];

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int acnt = 0, bcnt = 0, ccnt = 0;
  if (str[1] == 'a' || str[1] == '?') {
    f[1][1][0][0] = 1;
  }
  if (str[1] == 'b' || str[1] == '?') {
    f[1][0][1][1] = 1;
  }
  if (str[1] == 'c' || str[1] == '?') {
    f[1][0][0][2] = 1;
  }
  acnt += str[1] == 'a';
  bcnt += str[1] == 'b';
  ccnt += str[1] == 'c';
  for (int i = 2; i <= n; i++) {
    acnt += str[i] == 'a';
    bcnt += str[i] == 'b';
    ccnt += str[i] == 'c';
    for (int x = 0; x <= n; x++) {
      for (int y = 0; y + x <= n; y++) {
        int z = n - x - y;
        if (str[i] == 'a' || str[i] == '?') {
          f[i][x][y][0] += f[i - 1][x - 1][y][1] + f[i - 1][x - 1][y][2];
        }
        if (str[i] == 'b' || str[i] == '?') {
          f[i][x][y][1] += f[i - 1][x][y - 1][0] + f[i - 1][x][y - 1][2];
        }
        if (str[i] == 'c' || str[i] == '?') {
          f[i][x][y][2] += f[i - 1][x][y][0] + f[i - 1][x][y][1];
        }
      }
    }
  }
  while (q--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int ans = 0;
    for (int i =  )
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}