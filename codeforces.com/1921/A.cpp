#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

void solve() {
  int xmin = inf, xmax = -inf, ymin = inf, ymax = -inf;
  int x, y;
  for (int i = 0; i < 4; i++) {
    cin >> x >> y;
    xmin = min(xmin, x), xmax = max(xmax, x);
    ymin = min(ymin, x), ymax = max(ymax, x);
  }
  cout << (xmax - xmin) * (ymax - ymin) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}