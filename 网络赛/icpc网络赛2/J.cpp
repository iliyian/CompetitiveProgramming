#include <bits/stdc++.h>
#define int long long

struct Node {
  int w, v, c;
  bool operator < (const Node &b) const {
    return w * b.c < b.w * c;
  }
};

signed main() {
  freopen("J.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<Node> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].w >> a[i].v >> a[i].c;
  }
  std::sort(a.begin() + 1, a.end());
  int sumw = 0, ans = 0;
  for (int i = n; i >= 1; i--) {
    ans += a[i].v - a[i].c * sumw;
    sumw += a[i].w;
  }
  std::cout << ans << '\n';
  return 0;
}