// date: 2024-05-20 18:33:11
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Plat {
  int l, r, y;
  bool operator < (const Plat &b) const {
    return y > b.y;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<Plat> plats(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> plats[i].l >> plats[i].r >> plats[i].y;
  }
  plats[0] = {0, inf, 0};
  sort(plats.begin(), plats.end());
  int curx, cury;
  cin >> curx >> cury;
  for (auto [l, r, y] : plats) {
    if (cury > y) {
      if (l < curx && curx < r) {
        cury = y;
        if (y) {
          curx = r;
        }
      }
    }
  }
  cout << curx << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}