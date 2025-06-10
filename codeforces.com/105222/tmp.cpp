#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, y, r, vx, vy;
  std::cin >> x >> y >> r >> vx >> vy;
  int lx, ly, rx, ry;
  std::cin >> lx >> ly >> rx >> ry;
  
  if (ly + 2 * r > ry || lx + 2 * r > rx) {
    std::cout << "No\n";
    return;
  }
  if (x - r >= lx && x + r <= rx && y - r >= ly && y + r <= ry) {
    std::cout << "Yes\n";
    return;
  }

  int _lx = lx + r, _rx = rx - r, _ly = ly + r, _ry = ry - r;
  std::cerr << _lx << ' ' << _rx << ' ' << _ly << ' ' << _ry << '\n';
  double txl = double(_lx - x) / vx, txr = double(_rx - x) / vx;
  double tyl = double(_ly - y) / vy, tyr = double(_ry - y) / vy;
  if (vx == 0) {
    if (x - r >= lx && x + r <= rx) {
      txl = 0, txr = LLONG_MAX;
    } else {
      std::cout << "No\n";
      return;
    }
  }
  if (vy == 0) {
    if (y - r >= ly && y + r <= ry) {
      tyl = 0, tyr = LLONG_MAX;
    } else {
      std::cout << "No\n";
      return;
    }
  }
  if (txl > txr) std::swap(txl, txr);
  if (tyl > tyr) std::swap(tyl, tyr);
  // if (vx == 0) {
  //   if (tyl <= tyr && x + r <= rx && x - r >= lx) {
  //     std::cout << "Yes\n";
  //   } else {
  //     std::cout << "No\n";
  //   }
  //   return;
  // } else if (vy == 0) {
  //   if (txl <= txr) {
  //     std::cout << "Yes\n";
  //   } else {
  //     std::cout << "No\n";
  //   }
  //   return;
  // }
  std::cerr << txl << ' ' << txr << ' ' << tyl << ' ' << tyr << '\n';
  if (txr < tyl || tyr < txl) {
    std::cout << "No\n";
    return;
  }
  std::cout << "Yes\n";
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