#include <bits/stdc++.h>
#define int long long

struct Node {
  int l, r, w;
  bool operator < (const Node &b) const {
    return w > b.w;
  }
};

int p, a, b, q, c, d, m, t, ans = 0;
std::map<std::pair<int, int>, int> mem;
int work(int m, int t) {
  if (mem[{m, t}]) return mem[{m, t}];
  for (int x = 1; a * x + b + c * x + d <= t && p * x <= m; x++) {
    int nm = m + (q - p) * x;
  }
  return mem[{m, t}] = ans;
}

void solve() {
  std::cin >> p >> a >> b >> q >> c >> d >> m >> t;
  work(m, t);
  std::cout << ans << '\n';
  ans = 0;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("D.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}