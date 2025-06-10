#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pos[a[i]] = i;
  }
  while (q--) {
    int l, r, k;
    std::cin >> l >> r >> k;
    if (pos[k] < l || pos[k] > r) {
      std::cout << -1 << ' ';
      continue;
    }
    int lcnt = 0, rcnt = 0, ans = 0, lneed = 0, rneed = 0;
    bool f = true;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid] == k) break;
      if (pos[k] > mid) {
        if (a[mid] > k) {
          lneed++;
        }
        lcnt++;
        l = mid + 1;
      } else if (pos[k] < mid) {
        if (a[mid] < k) {
          rneed++;
        }
        rcnt++;
        r = mid - 1;
      }
      if (lcnt > k - 1 || rcnt > n - k) {
        f = false;
        break;
      }
    }
    // std::cerr << lcnt << ' ' << rcnt << ' ' << lneed << ' ' << rneed << ' ' << k << '\n';
    if (!f) {
      std::cout << -1 << ' ';
      continue;
    }
    std::cout << std::max(lneed, rneed) * 2 << ' ';
  }
  std::cout << '\n';
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