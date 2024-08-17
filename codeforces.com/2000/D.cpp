#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    while (l <= r && str[l] != 'L') l++;
    while (l <= r && str[r] != 'R') r--;
    ans += a[r] - a[l - 1];
    l++, r--;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}