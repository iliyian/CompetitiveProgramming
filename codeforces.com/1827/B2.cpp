// date: 2024-07-19 09:01:49
// tag: 构造，rmq

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> mn(n + 1, std::vector<int>(21)),
    mx(n + 1, std::vector<int>(21));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += (n - i) * (n - i + 1) / 2;
    mn[i][0] = mx[i][0] = a[i];
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
      mn[i][j] = std::min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
      mx[i][j] = std::max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
  }

  auto querymn = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::min(mn[l][len], mn[r - (1 << len) + 1][len]);
  };

  auto querymx = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[l][len], mx[r - (1 << len) + 1][len]);
  };

  for (int i = 1; i <= n; i++) {

    int L = 1, R = i - 1, l = 0;
    while (L <= R) {
      int mid = (L + R) / 2;
      if (querymn(mid, i - 1) < a[i]) l = mid, L = mid + 1;
      else R = mid - 1;
    }

    // while (l >= 1 && a[l] >= a[i]) l--;

    L = i + 1, R = n;
    int r = n + 1;
    while (L <= R) {
      int mid = (L + R) / 2;
      if (querymn(i + 1, mid) < a[i]) r = mid, R = mid - 1;
      else L = mid + 1;
    }
    // while (r <= n && a[r] >= a[i]) r++;

    L = 1, R = l - 1;
    int k = 0;
    while (L <= R) {
      int mid = (L + R) / 2;
      if (querymx(mid, l - 1) > a[i]) k = mid, L = mid + 1;
      else R = mid - 1;
    }

    // while (k >= 1 && a[k] <= a[i]) k--;
    ans -= (l - k) * (r - i);

    // std::cout << l << ' ' << k << ' ' << r << ' ' << i << '\n';
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}