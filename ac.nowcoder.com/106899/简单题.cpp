#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::vector<int> vec;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    vec.push_back(a[i]);
  }
  std::sort(vec.begin(), vec.end());
  auto id = [&](int x) {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  std::vector<std::vector<int>> pos(n + 1);
  std::vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = id(a[i]);
    pos[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    pos[a[i]].push_back(n + 1);
  }
  k = n * (n + 1) / 2 - k + 1;
  int i = 1;
  while (1) {
    for (int j = i + 1; j <)
      int len = pos[a[i]].size() * (n + 1) - s[a[i]];
      if (k > len) {
        k -= len;
      }
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