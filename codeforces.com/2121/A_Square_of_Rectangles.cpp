#include <bits/stdc++.h>
#define int long long

void solve() {
  int l1, b1, l2, b2, l3, b3;
  std::cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
  if (l1 == l2 && l2 == l3 && (b1 + b2 + b3) == l1) {
    std::cout << "YES\n";
    return;
  }
  if (l1 == l2 + l3 && b2 == b3 && b2 + b1 == l1 || l2 == l1 + l3 && b1 == b3 && b1 + b2 == l2 || l3 == l2 + l1 && b1 + b3 == l3) {
    std::cout << "YES\n";
    return;
  }
  std::swap(l1, b1);
  std::swap(l2, b2);
  std::swap(l3, b3);
  if (l1 == l2 && l2 == l3 && (b1 + b2 + b3) == l1) {
    std::cout << "YES\n";
    return;
  }
  if (l1 == l2 + l3 && b2 == b3 && b2 + b1 == l1 || l2 == l1 + l3 && b1 == b3 && b1 + b2 == l2 || l3 == l2 + l1 && b1 + b3 == l3) {
    std::cout << "YES\n";
    return;
  }
  std::cout << "NO\n";
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