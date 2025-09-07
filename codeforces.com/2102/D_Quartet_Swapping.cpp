#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), d(n + 1);
  auto add = [&](int x, int c) {
    for (int i = x; i > 0; i -= i & -i) d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i <= n; i += i & -i) ans += d[i];
    return ans;
  };
  int raw = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    raw += i - 1 - query(a[i]);
    add(a[i], 1);
  }
  std::array<std::vector<int>, 2> v;
  for (int i = 1; i <= n; i++) {
    v[i % 2].push_back(a[i]);
  }
  for (int i = 0; i < 2; i++) {
    std::sort(v[i].begin(), v[i].end());
  }
  auto b = a;
  for (int i = 1; i <= n; i++) {https://codeforces.com/gym/105158
    b[i] = v[i % 2][(i - 1) / 2];
  }
  int cur = 0;
  std::ranges::fill(d, 0);
  for (int i = 1; i <= n; i++) {
    cur += i - 1 - query(b[i]);
    add(b[i], 1);
  }
  if (cur % 2 != raw % 2) {
    std::swap(b[n], b[n - 2]);
  } 
  // std::cerr << raw << ' ' << cur << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << b[i] << ' ';
  }
  std::cout << '\n';
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