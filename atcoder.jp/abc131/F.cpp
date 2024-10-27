// date: 2024-10-25 09:07:50
// tag: 经典二维点转边，并查集

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> pa(N * 2 + 1), siz(N * 2 + 1, 1), w(N * 2 + 1), h(N * 2 + 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    merge(x, y + N);
  }
  for (int i = 1; i <= N; i++) {
    w[find(find, i)]++;
  }
  for (int i = N + 1; i <= N * 2; i++) {
    h[find(find, i)]++;
  }
  int ans = -n;
  for (int i = 1; i <= N * 2; i++) {
    if (i == pa[i]) {
      ans += w[i] * h[i];
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}