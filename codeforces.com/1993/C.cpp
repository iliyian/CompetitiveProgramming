// date: 2024-08-12 15:24:26
// tag: qianzhuihe

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::vector<int> s(k * 2 + 5);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    int l = a[i] % (2 * k);
    if (l <= k) {
      int r = l + k - 1;
      s[l]++, s[r + 1]--;
    } else {
      int r = (l + k - 1) % (2 * k);
      s[r + 1]--, s[0]++, s[l]++;
    }
  }
  for (int i = 1; i <= k * 2; i++) {
    s[i] += s[i - 1];
  }
  bool f = false;
  for (int i = 0; i <= k * 2; i++) {
    if (s[(i + a[n]) % (2 * k)] == n) {
      std::cout << i + a[n] << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
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