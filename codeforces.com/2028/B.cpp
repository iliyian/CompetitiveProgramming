#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, b, c;
  std::cin >> n >> b >> c;
  if (b == 0) {
    std::cout << (c >= n ? n : c >= n - 2 ? n - 1 : -1) << '\n';
    return;
  }
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (__int128(mid - 1) * b + c > n - 1) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  if (ans == -1) {
    std::cout << 0 << '\n';
  } else {
    std::cout << n - ans + 1 << '\n';
  }
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