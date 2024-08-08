#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 2e5;

std::vector<int> f(N + 1);

void solve() {
  int l, r;
  std::cin >> l >> r;
  int ans = 0, t = l;
  while (t > 0) {
    ans += 2;
    t /= 3;
  }
  ans += f[r] - f[l];
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  f[1] = 1;
  for (int i = 2; i <= N; i++) {
    f[i] = std::ceil(double(std::log(i)) / std::log(3));
  }
  for (int i = 3; i <= N; i *= 3) {
    f[i]++;
  }
  for (int i = 1; i <= N; i++) {
    f[i] += f[i - 1];
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}