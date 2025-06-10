#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int fac(int n) {
  int ans = 1;
  for (int i = n; i >= 2; i--) {
    ans = ans * i % mod;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), s(n + 1);
  std::vector<std::vector<int>> mx(15, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx[0][i] = a[i];
    s[i] = s[i - 1] + (a[i] == -1);
  }
  for (int i = 1; i <= 14; i++) {
    for (int j = i - (1ll << (i - 1)) + 1; j >= 1; j--) {
      mx[i][j] = std::max(mx[i - 1][j], mx[i - 1][j + (1ll << (i - 1)) - 1]);
    }
  }
  auto getmx = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[len][l], mx[len][r - (1ll << len) + 1]);
  };
  int ans = fac(s[n]) * (n - 1) % mod;
  for (int mex = 1; mex <= n; mex++) {
    for (int l = 1; l + mex - 1 <= n; mex++) {
      int r = l + mex - 1;
      int cnt = s[r] - s[l - 1];
      if (getmx(l, r) <= mex - 1) {
        int in = fac(cnt);
        int out = fac(s[n] - cnt);
        ans += in * out % mod * mex;
        std::cerr << l << ' ' << r << ' ' << mex << '\n';
      }
    }
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