#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  std::sort(a.begin() + 1, a.end());
  a.erase(std::unique(a.begin() + 1, a.end()), a.end());
  int ans = 0;
  for (int i = 1; i < a.size(); i++) {
    int x = std::min(cnt[a[i]], m / a[i]);
    ans = std::max(ans, x * a[i]);
  }
  for (int i = 1; i < a.size() - 1; i++) {
    if (a[i + 1] - a[i] == 1) {
      int cur = 0;
      int x = a[i], y = a[i + 1];
      int cntx = cnt[a[i]], cnty = cnt[a[i + 1]];
      for (int j = 1; j <= cntx; j++) {
        if (j * x > m) break;
        int r = m - j * x;
        int k = std::min(r / y, cnty);
        cur = std::max(cur, j * x + k * y);
      }
      ans = std::max(ans, cur);
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}