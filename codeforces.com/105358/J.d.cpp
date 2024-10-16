#include <bits/stdc++.h>
#include <random>
#define int long long

struct Node {
  int l, r, w;
  bool operator < (const Node &b) const {
    return w > b.w;
  }
};

std::mt19937 rd(std::random_device{}());

void solve() {
  // int n = rd() % (int)1e1 + 1;
  int n = 100;
  std::cout << n << '\n';
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      b[i][j] = b[j][i] = rd() % (int)1e6 + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % (int)1e1 + 1 << ' ';
  }
  std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << b[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("J.in", "w", stdout);
  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}