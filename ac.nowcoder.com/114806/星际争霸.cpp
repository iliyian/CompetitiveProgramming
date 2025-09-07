#include <bits/stdc++.h>
#define int long long

void solve() {
  int s, b;
  std::cin >> s >> b;
  std::vector<int> a(s);
  std::vector<int> vec = {LLONG_MIN};
  auto id = [&](int x) {
    return std::ranges::lower_bound(vec, x) - vec.begin();
  };
  for (int i = 0; i < s; i++) {
    std::cin >> a[i];
    vec.push_back(a[i]);
  }
  std::vector<int> d(b), g(b);
  for (int i = 0; i < b; i++) {
    std::cin >> d[i] >> g[i];
    vec.push_back(d[i]);
  }
  std::ranges::sort(vec);
  int m = vec.size();
  std::vector<int> fenwick(m + 1);
  auto add = [&](int x, int c) -> void {
    for (int i = x; i <= m; i += i & -i) fenwick[i] += c;
  };
  auto query = [&](int x) -> int {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += fenwick[i];
    return ans;
  };
  for (int i = 0; i < b; i++) {
    add(id(d[i]), g[i]);
  }
  for (int i = 0; i < s; i++) {
    std::cout << query(id(a[i])) << ' ';
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