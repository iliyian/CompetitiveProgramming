#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int x, y, r, vx, vy;
  std::cin >> x >> y >> r >> vx >> vy;
  int lx, ly, rx, ry;
  std::cin >> lx >> ly >> rx >> ry;

  lx += r, ly += r, rx -= r, ry -= r;
  if (lx > rx || ly > ry) {
    std::cout << "No\n";
    return;
  }
  // cerr << x <<" "<<y<<" "<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<"\n";
  if(x > rx && vx >= 0 || x < lx && vx <= 0 || y > ry && vy >= 0 || y < ly && vy <= 0){
    cout << "No\n";
    return;
  }

  if(vx == 0){
    if(x >= lx && x <= rx)cout << "Yes\n";
    else  cout << "No\n";
    return;
  }
  if(vy == 0){
    if(y >= ly && y <= ry)cout << "Yes\n";
    else  cout << "No\n";
    return;
  }


  int b = vx * y - vy * x;
  if(vx * vy > 0){
    int ul = vx * ry - vy * lx - b;
    int dr = vx * ly - vy * rx - b;
    if(ul >= 0 && dr <= 0 || ul <= 0 && dr >= 0)cout << "Yes\n";
    else  cout << "No\n";
    return;
  }
  else{
    int dl = vx * ly - vy * lx - b;
    int ur = vx * ry - vy * rx - b;
    if(dl >= 0 && ur <= 0 || dl <= 0 && ur >= 0)cout << "Yes\n";
    else  cout << "No\n";
    return;
  }


  
//   if (ly + 2 * r > ry || lx + 2 * r > rx) {
//     std::cout << "No\n";
//     return;
//   }
//   if (x - r >= lx && x + r <= rx && y - r >= ly && y + r <= ry) {
//     std::cout << "Yes\n";
//     return;
//   }
// 
//   int _lx = lx + r, _rx = rx - r, _ly = ly + r, _ry = ry - r;
//   double txl = double(_lx - x) / vx, txr = double(_rx - x) / vx;
//   double tyl = double(_ly - y) / vy, tyr = double(_ry - y) / vy;
//   if (vx == 0) {
//     if (x - r >= lx && x + r <= rx) {
//       txl = 0, txr = LLONG_MAX;
//     } else {
//       std::cout << "No\n";
//       return;
//     }
//   }
//   if (vy == 0) {
//     if (y - r >= ly && y + r <= ry) {
//       tyl = 0, tyr = LLONG_MAX;
//     } else {
//       std::cout << "No\n";
//       return;
//     }
//   }
//   // if (vx == 0) {
//   //   if (tyl <= tyr && x + r <= rx && x - r >= lx) {
//   //     std::cout << "Yes\n";
//   //   } else {
//   //     std::cout << "No\n";
//   //   }
//   //   return;
//   // } else if (vy == 0) {
//   //   if (txl <= txr) {
//   //     std::cout << "Yes\n";
//   //   } else {
//   //     std::cout << "No\n";
//   //   }
//   //   return;
//   // }
//   std::cerr << txl << ' ' << txr << ' ' << tyl << ' ' << tyr << '\n';
//   if (txl < 0 || txr < 0 || tyl < 0 || tyr < 0 || txl > txr || tyl > tyr) {
//     std::cout << "No\n";
//     return;
//   }
//   if (txr < tyl || tyr < txl) {
//     std::cout << "No\n";
//     return;
//   }
//   std::cout << "Yes\n";
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