#include <bits/stdc++.h>
#define int long long

int fac(int n) {
  if (n == 0) return 1;
  return n * fac(n - 1);
}

void solve() {
  int N = 9;
  std::vector<int> res(N + 1);
  int pre = 0;
  for (int n = 1; n <= N; n++) {
    std::vector<int> p(n);
    std::ranges::iota(p, 0);
    int ans = 0;
    do {
      for (int i = 0; i < n; i++) {
        std::vector<int> cnt(n);
        int mex = 0;
        for (int j = i; j < n; j++) {
          cnt[p[j]]++;
          while (mex < n && cnt[mex]) mex++;
          ans += mex;
        }
      }
    } while (std::next_permutation(p.begin(), p.end()));
    res[n] = ans;
    // std::cout << ans - pre << '\n';
    // pre = ans;
    std::cout << ans << ' ' << fac(n + 1) * n / 2 << ' ' << (n + 1) * ans + (n + 1) * fac(n + 1) << '\n';
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