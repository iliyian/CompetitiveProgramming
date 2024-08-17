#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e6;
std::vector<int> cnt(N + 1);

void solve() {
  int n, k, d, w;
  std::cin >> n >> k >> d >> w;
  std::vector<int> t(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> t[i];
    cnt[t[i]]++;
  }
  t[n + 1] = LLONG_MAX;
  int lst = n, ans = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (t[lst] - t[i] > d + w || lst - i + 1 > k) {
      ans++;
      lst = i;
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