#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto check = [&](int mid) {
    int sum = 0;
    for (int i = 1; i <= n; i++)  {
      sum += std::max(0ll, mid - a[i]);
    }
    return sum;
  };
  int l = 0, r = 1e12 + 5, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid) <= k) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  int cnt = 0, res = (ans - 1) * n + 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > ans) {
      cnt++;
    }
  }
  std::cout << cnt + (k - check(ans)) + res << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}