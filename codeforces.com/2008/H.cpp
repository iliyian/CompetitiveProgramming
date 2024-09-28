// date: 2024-09-03 15:19:16
// tag: 二分，调和级数，中位数，数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    c[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    c[i] += c[i - 1];
  }
  auto check = [&](int mid, int x) {
    int cnt = 0;
    for (int i = 0; i <= n; i += x) {
      cnt += c[std::min(i + mid, n)] - (i >= 1 ? c[i - 1] : 0);
    }
    return cnt >= (n + 2) / 2;
  };
  std::vector<int> ans(n + 1);
  for (int x = 1; x <= n; x++) {
    int l = 0, r = x - 1;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      if (check(mid, x)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (check(l, x)) r = l;
    ans[x] = r;
  }
  while (q--) {
    int x;
    std::cin >> x;
    std::cout << ans[x] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}