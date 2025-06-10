#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e7;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> x(n + 1);
  std::vector<std::array<int, 2>> trie(N + 1);
  std::vector<int> rev(N + 1);
  int tot = 1;
  auto insert = [&](int x, int id) {
    int cur = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!trie[cur][idx]) trie[cur][idx] = ++tot;
      cur = trie[cur][idx];
    }
    rev[cur] = id;
  };
  auto query = [&](int x, int tag) {
    int cur = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (trie[cur][idx ^ tag]) cur = trie[cur][idx ^ tag];
      else cur = trie[cur][idx ^ 1 ^ tag];
      // if (!cur) {
      //   std::cout << x << ' ' << tag << ' ' << i << '\n';
      // }
    }
    // std::cerr << x << ' ' << tag << ' ' << cur << '\n';
    return rev[cur];
  };
  auto sgn = [&](int x) {
    return x > 0 ? 1 : x < 0 ? -1 : 0;
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i];
    insert(x[i], i);
  }
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    int mn_pos = query(a, 0);
    int mx_pos = query(a, 1);
    // std::cerr << mn_pos << ' ' << mx_pos << '\n';
    if ((x[mn_pos] ^ a) > b || (x[mx_pos] ^ a) < b) {
      std::cout << -1 << '\n';
      continue;
    }
    int l = std::min(mn_pos, mx_pos), r = std::max(mn_pos, mx_pos);
    if (l == r) {
      if (sgn((x[1] ^ a) - b) * sgn((x[2] ^ 1) - b) <= 0) {
        std::cout << 1 << '\n';
      } else {
        std::cout << -1 << '\n';
      }
      continue;
    }
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (sgn((x[l] ^ a) - b) * sgn((x[mid] ^ a) - b) <= 0) {
        r = mid;
      } else {
        l = mid;
      }
    }
    if (sgn((x[l] ^ a) - b) * sgn((x[r] ^ a) - b) <= 0) {
      std::cout << l << '\n';
    } else {
      std::cout << -1 << '\n';
    }
  }
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