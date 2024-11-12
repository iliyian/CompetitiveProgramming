#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int l, r, w;
  bool operator < (const Node &b) const {
    return w > b.w;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Node> a(n + 1);
  int lowt = 0, loww = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].w >> a[i].l >> a[i].r;
    lowt += a[i].l;
    loww += a[i].w * a[i].l;
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<int> pret(n + 1), prew(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int curt = lowt - a[i].l;
    int curw = loww - a[i].l * a[i].w;
    int p = std::upper_bound(pret.begin() + 1, pret.begin() + i, m - curt) - pret.begin() - 1;
    ans = std::max(ans, prew[p] + curw + (m - curt - pret[p]) * a[p + 1].w);
    pret[i] = pret[i - 1] + a[i].r - a[i].l;
    prew[i] = prew[i - 1] + (a[i].r - a[i].l) * a[i].w;
  }
  std::cout << ans << '\n';
}

signed main() 
{
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) 
  {
    solve();
  }
  return 0;
}