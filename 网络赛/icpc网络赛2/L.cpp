#include <bits/stdc++.h>
#define int long long

double check(int mid, int n) {
  return 
}

std::map<int, std::pair<int, int>> mem;

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 1 << ' ' << 1 << '\n';
    return;
  } else if (n == 2) {
    std::cout << 3 << ' ' << 2 << '\n';
    return;
  }
  if (mem[n].second) {
    std::cout << mem[n].first << ' ' << mem[n].second << '\n';
    return;
  }
  int l = 3, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid, n) <= mid) r = mid;
    else l = mid + 1;
  }
  int d = std::gcd(l, n);
  mem[n] = {l / d, n / d};
  std::cout << l / d << ' ' << n / d << '\n';
}

signed main() {
  freopen("L.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}