#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> void {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  std::map<int, std::vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] -= i;
    mp[a[i]].push_back(i);
  }
  int ans = 0;
  for (auto &[k, v] : mp) {
    for (int j = v.size() - 1; j > 0; j -= 2) {
      ans += std::max(0ll, v[j] + v[j - 1] + k * 2);
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}