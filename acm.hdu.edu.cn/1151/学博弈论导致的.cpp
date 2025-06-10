#include <bits/stdc++.h>
#define int long long

std::map<std::array<int, 3>, int> vis;

std::map<int, int> num;

constexpr int N = 1e9;

int sg(int r, int b, int m) {
  int x = r * N * N + b * N + m;
  if (!r && !b && !m)
    return 0;
  if (num.count(x)) return num[x];
  std::set<int> s;
  for (int i = 1; i <= std::min(r, 3ll); i++) {
    s.insert(sg(r - i, b, m));
  }
  if (r > 0) {
    s.insert(sg(r - 1, b + 1, m));
  }
  if (b > 0) {
    s.insert(sg(r, b - 1, m));
    if (r > 1) {
      s.insert(sg(r - 1, b - 1, m));
    }
  }
  if (b > 1) {
    s.insert(sg(r + 1, b - 2, m));
  }
  if (m > 0) {
    s.insert(sg(r + 1, b, m - 1));
    s.insert(sg(r, b + 1, m - 1));
    s.insert(sg(r + 1, b, m - 1));
  }
  for (int i = 0;; i++) {
    if (!s.count(i)) {
      return num[x] = i;
    }
  }
}

int dfs(int r, int b, int m) {
  if (!r && !b && !m)
    return -1;
  if (vis.count({r, b, m})) return vis[{r, b, m}];
  for (int i = 1; i <= std::min(r, 3ll); i++) {
    if (dfs(r - i, b, m) == -1) {
      return vis[{r, b, m}] = 1;
    }
  }
  if (r > 0 && dfs(r - 1, b + 1, m) == -1) {
    return vis[{r, b, m}] = 1;
  }
  if (b > 0) {
    if (dfs(r, b - 1, m) == -1) {
      return vis[{r, b, m}] = 1;
    }
    if (r > 1 && dfs(r - 1, b - 1, m) == -1) {
      return vis[{r, b, m}] = 1;
    }
  }
  if (b > 1 && dfs(r + 1, b - 2, m) == -1) {
    return vis[{r, b, m}] = 1;
  }
  if (m > 0) {
    if (dfs(r + 1, b, m - 1) == -1)
      return vis[{r, b, m}] = 1;
    if (dfs(r, b + 1, m - 1) == -1)
      return vis[{r, b, m}] = 1;
    if (dfs(r + 1, b + 1, m - 1) == -1)
      return vis[{r, b, m}] = 1;
  }
  return vis[{r, b, m}] = -1;
}

void solve() {
  int r, b, m;
  std::cin >> r >> b >> m;
  if (!r && !b) {
    std::cout << "Bob\n";
    return;
  }
  if (r % 2 == 0) {
    if (r / 2 % 2 == b % 2) {
      std::cout << "Bob\n";
    } else {
      std::cout << "Alice\n";
    }
  } else {
    std::cout << "Alice\n";
  }
  return;
  int x = sg(r, b, m);
  if (x == 0) {
    // std::cout << r << ' ' << b << ' ' << m << '\n';
    std::cout << r << ' ' << b << '\n';
    return;
  }
  // std::cout << r << ' ' << b << ' ' << m << ' ' << sg(r, b, m) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}