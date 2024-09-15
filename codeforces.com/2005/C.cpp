#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string narek = "narek";
  std::vector<std::array<int, 5>> f(n + 1);
  f[0].fill(INT_MIN);
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    str = '#' + str;
    for (int j = 0; j < 5; j++) {
      f[i][j] = f[i - 1][j];
    }
    for (int j = 0; j < 5; j++) {
      // if (f[i][j] == INT_MIN) continue;
      int pos = j, cnt = 0;
      for (int k = 1; k <= m; k++) {
        if (narek.find(str[k]) == str.npos) {
          continue;
        }
        if (str[k] == narek[pos]) {
          pos = (pos + 1) % 5;
          cnt++;
        } else {
          cnt--;
        }
      }
      f[i][pos] = std::max(f[i][pos], f[i - 1][j] + cnt);
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    ans = std::max(ans, f[n][i] - 2 * i);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}