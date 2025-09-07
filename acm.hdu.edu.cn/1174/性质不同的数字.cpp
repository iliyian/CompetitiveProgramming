#include <bits/stdc++.h>
#define int long long

using u64 = unsigned long long;
std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> vec;
  auto id = [&](int x) {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  std::vector<std::pair<int, int>> a;
  for (int i = 1; i <= n; i++) {
    int l, r;
    std::cin >> l >> r;
    vec.push_back(l);
    if (l != r) {
      vec.push_back(l + 1);
    }
    vec.push_back(r);
    vec.push_back(r + 1);
    a.push_back({l, r});
  }
  vec.push_back(LLONG_MAX / 3);
  std::ranges::sort(vec);
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  int m = vec.size();
  std::vector<u64> v(m + 2);
  // int t = 0;
  for (auto [l, r] : a) {
    u64 val = rd();
    // u64 val = (1 << t++);
    v[id(r) + 1] ^= val;
    v[id(l)] ^= val;
  }
  std::set<u64> s;
  s.insert(0);
  for (int i = 0; i <= m + 1; i++) {
    if (i) {
      v[i] ^= v[i - 1];
    }
    s.insert(v[i]);
  }
  std::cout << s.size() << '\n';
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