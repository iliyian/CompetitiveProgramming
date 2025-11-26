#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string a, b, c;
  std::cin >> a >> b >> c;
  if (a.size() != b.size()) {
    std::cout << "NO\n";
    return;
  }
  if (a.size() != c.size()) {
    std::cout << "YES\n";
    return;
  }
  int pa[26], siz[26];
  std::iota(pa, pa + 26, 0);
  std::fill(siz, siz + 26, 1);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  for (int i = 0; i < a.size(); i++) {
    merge(a[i] - 'a', b[i] - 'a');
  }
  bool f = false;
  for (int i = 0; i < c.size(); i++) {
    if (find(a[i] - 'a') != find(c[i] - 'a')) {
      f = true;
    }
  }
  std::cout << (f ? "YES" : "NO") << '\n';
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