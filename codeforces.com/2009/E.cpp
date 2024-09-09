#include <bits/stdc++.h>
#define int long long
// using namespace std;

int n, k;

int calc(int x) {
  return (k + k + x - 1) * x / 2 - (k + x + k + n - 1) * (n - x) / 2;
}

void solve() {
  std::cin >> n >> k;
  int l = 1, r = n;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (calc(mid) > 0) r = mid;
    else l = mid;
  }
  std::cout << std::min(std::abs(calc(l)), std::abs(calc(r))) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}