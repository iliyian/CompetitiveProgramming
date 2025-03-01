#include <algorithm>
#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;

// std::vector<std::vector<int>> mx(18, std::vector<int>(N + 1)), mn(18, std::vector<int>(N + 1));
int mx[18][N + 2], mn[18][N + 2], a[N + 2], ll[N + 2], rle[N + 2];

void solve() {
  int n, k;
  std::cin >> n >> k;
  // std::vector<int> a(n + 1);
  a[0] = a[n + 1] = -2e9 - 10;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx[0][i] = mn[0][i] = a[i];
  }
  k = n * (n + 1) / 2 - k + 1;
  for (int i = 1; i <= 17; i++) {
    for (int j = n - (1 << (i - 1)); j >= 1; j--) {
    // for (int j = 1; j + (1 << (i - 1)) <= n; j++) {
      mx[i][j] = std::max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
      mn[i][j] = std::min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
    }
  }
  auto getmx = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[len][l], mx[len][r - (1 << len) + 1]);
  };
  auto getmn = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::min(mn[len][l], mn[len][r - (1 << len) + 1]);
  };
  std::vector<int> b;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      // int mn = a[i], mx = a[i];
      // for (int k = i; k <= j; k++) {
      //   mn = std::min(mn, a[k]);
      //   mx = std::max(mx, a[k]);
      // }
      b.push_back(getmx(i, j) + getmn(i, j));
      // b.push_back(mn + mx);
    }
  }
  std::sort(b.begin(), b.end());
  // std::cout << k << '\n';
  // for (int i = 0; i < b.size(); i++) {
  //   std::cout << b[i] << ' ';
  // }
  // std::cout << '\n';
  std::cout << b[k - 1] << '\n';

  return;

  for (int i = 1; i <= n; i++) {
    int l = 0, r = i;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (getmn(mid, i) < a[i]) ll[i] = mid, r = mid - 1;
      else l = mid + 1;
    }
    l = i, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (getmn(i, mid) <= a[i]) l = mid + 1, rle[i] = mid;
      else r = mid - 1;
    }
    // std::cerr << ll[i] + 1 << ' ' << rle[i] - 1 << '\n';
  }

  auto check = [&](int mi) -> bool {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] + a[i] > mi) continue;
      int _l = ll[i] + 1, _r = i, l = 0;
      while (_l <= _r) {
        int mid = (_l + _r) / 2;
        auto mx = getmx(mid, i);
        if (mx <= mi - a[i]) _r = mid - 1, l = mid;
        else _l = mid + 1;
      }
      _l = i, _r = rle[i] - 1;
      // if (!l) continue;
      int r = 0;
      while (_l <= _r) {
        int mid = (_l + _r) / 2;
        auto mx = getmx(mid, n);
        if (mx <= mi - a[i]) _l = mid + 1, r = mid;
        else _r = mid - 1;
      }
      // std::cerr << mi << ' ' << a[i] << ' ' << l << ' ' << r << '\n';
      if (!l || !r) continue;
      cnt += (i - l + 1) * (r - i + 1);
    }
    // std::cerr << mi << ' ' << cnt << '\n';
    return cnt >= k;
  };
  int l = 0, r = 2e9 + 10, ans = -1;
  while (l <= r) {
    int mi = (l + r) / 2;
    if (check(mi)) r = mi - 1, ans = mi;
    else l = mi + 1;
  }
  std::cout << ans << '\n';
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