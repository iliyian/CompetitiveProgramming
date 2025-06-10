#include <bits/stdc++.h>
#define int long long

void solve() { 
  int n, m;
  std::cin >> n >> m;
  if (n >= (1ll << m)) {
    std::cout << -1 << '\n';
    return;
  }
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    int mx = std::max(mid, n - mid);
    if (mx <= (1ll << (m - 2))) {
      r = mid - 1, ans = mid;
    } else {
      l = mid + 1;
    }
  }
  std::cout << ans << '\n';
}

// [1,28]

// 1 2 4 8 12 13

// [1,15]+12 27]
// [1,15]+25 [26
// [1,1]+4
// [1,3]+2
// 50, 7
// [1,2,4,8,16,9,10] // [1,15],35

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}