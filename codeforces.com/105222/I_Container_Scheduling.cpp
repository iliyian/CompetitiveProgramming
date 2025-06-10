#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, l, h;
  std::cin >> n >> l >> h;
  std::vector<std::array<int, 4>> a;
  auto check = [&](int lx, int ly, int rx, int ry) {
    if (rx > l || ry > h) {
      return false;
    }
    for (auto [_lx, _ly, _rx, _ry] : a) {
      if(lx < _rx && ly < _ry && _lx < rx && _ly < ry){
        // if (lx == 5 && ly == 0 && rx == 9 && ry == 7) {
        //   std::cerr << "qwq\n";
        //   std::cerr << _lx << ' ' << _ly << ' ' << _rx << ' ' << _ry << '\n';
        //   std::cerr << lx << ' ' << ly << ' ' << rx << ' ' << ry << '\n';
        // }
        return false;
      }
      // if (!((_lx > rx || _rx < lx) && (_ly > ry || _ry < ly))) {
      // if (_lx >= rx || lx >= _rx || _ly >= ry || ly >= _ry) {
      //   return false;
      // }
    }
    return true;
  };
  std::set<int> sx, sy;
  sx.insert(0);
  sy.insert(0);
  for (int i = 1; i <= n; i++) {
    bool f = false;
    int w, h, ansx = -1, ansy = -1;
    std::cin >> w >> h;
    for (int x : sx) {
      for (int y : sy) {
        if (check(x, y, x + w, y + h)) {
          f = true;
          ansx = x, ansy = y;
          break;
        }
      }
      if (f) {
        break;
      }
    }
    if (f) {
      std::cout << ansx << ' ' << ansy << '\n';
      sx.insert(ansx + w);
      sy.insert(ansy + h);
      a.push_back({ansx, ansy, ansx + w, ansy + h});
    } else {
      std::cout << -1 << '\n';
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