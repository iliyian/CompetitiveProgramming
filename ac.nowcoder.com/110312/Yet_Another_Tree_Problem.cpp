#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), s(n + 2);
  double e2x = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s[i] = s[i - 1] + a[i];
    e2x += a[i];
  }
  std::sort(a.begin() + 1, a.end());
  e2x = (e2x - m) / n;
  e2x = e2x * e2x;
  int l = 0, r = 1e9, ans = -1, cntl = 0, cntr = 0;
  while (l <= r) {
    int mid = (l + r) / 2; // 若干个mid和mid+1
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] > mid + 1) {
        sum += a[i];
        cnt++;
      }
    }
    sum -= m;
    if (cnt && sum / cnt > mid) {
      l = mid + 1;
    } else {
      r = mid - 1;
      if (cnt) {
        int rest = sum - (sum / cnt * cnt);
        ans = mid;
        cntl = sum / cnt, cntr = rest;
      }
    }
  }
  std::cerr << ans << ' ' << cntl << ' ' << cntr << '\n';
  double ex2 = ans * ans * cntl + (ans + 1) * (ans + 1) * cntr;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= ans + 1) {
      ex2 += a[i] * a[i];
    }
  }
  std::cout << ex2 / n - e2x << '\n';
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