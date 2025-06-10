#include <bits/stdc++.h>
#define int long long

void solve() {
  std::map<int, int> mp;
  mp[1] = 5;
  mp[2] = 2;
  mp[3] = 0;
  auto get = [&](auto self, int x) -> int {
    if (mp.count(x)) {
      return mp[x];
    }
    return mp[x] = (self(self, x - 3) + self(self, x - 2) + self(self, x - 1)) % 10;
  };
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cout << get(get, i);
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