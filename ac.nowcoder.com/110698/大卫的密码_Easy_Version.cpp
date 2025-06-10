#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  s--, t--;
  std::vector<std::vector<int>> a(n, std::vector<int>(m)), S(n * 2, std::vector<int>(m));;
  std::vector<std::vector<int>> f(n * 2, std::vector<int>(m, LLONG_MIN / 3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int y = 0; y < m; y++) {
    for (int x = 0; x < n * 2; x++) {
      S[x][y] = (x == 0 ? 0 : S[x - 1][y]) + a[x % n][y];
    }
  }
  for (int x = s; x < s + n; x++) {
    f[x % n][0] = (x == s ? 0 : f[(x + n - 1) % n][0]) + a[x % n][0];
  }
  auto get = [&](int t, int y) {
    return f[t][y - 1] - (t == 0 ? 0 : S[t - 1][y]);
  };
  for (int y = 1; y < m; y++) {
    std::deque<int> q;
    for (int x = 0; x < n * 2; x++) { 
      while (!q.empty() && q.front() <= x - n) q.pop_front();
      while (!q.empty() && get(q.back(), y) < get(x, y)) {
        q.pop_back();
      }
      q.push_back(x);
      f[x][y] = S[x][y] + get(q.front(), y);
    }
    for (int x = 0; x < n; x++) {
      f[x][y] = f[x + n][y] = std::max(f[x][y], f[x + n][y]);
    }
  }
  std::cout << f[t + n][m - 1] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}