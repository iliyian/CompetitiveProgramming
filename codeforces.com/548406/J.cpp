#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int l, r, x, a, b;
  std::cin >> l >> r >> x >> a >> b;
  if (b < l || b > r) {
    std::cout << -1 << '\n';
    return;
  }
  if (a == b) {
    std::cout << 0 << '\n';
    return;
  }
  if (std::abs(a - b) >= x) {
    std::cout << 1 << '\n';
    return;
  }
  if (b - l >= x && std::abs(a - l) >= x) {
    std::cout << 2 << '\n';
    return;
  }
  if (r - b >= x && std::abs(a - r) >= x) {
    std::cout << 2 << '\n';
    return;
  }
  if (r - l >= x && std::abs(a - r) >= x && b - l >= x) {
    std::cout << 3 << '\n';
    return;
  }
  if (r - l >= x && std::abs(a - l) >= x && r - b >= x) {
    std::cout << 3 << '\n';
    return;
  }
  std::cout << -1 << '\n';
}

signed main() {
  freopen("J.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}