#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> b = {0}, r = {0};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int rcnt = 0, bcnt = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == 'R') {
      r.push_back(a[i]);
      rcnt++;
    } else {
      b.push_back(a[i]);
      bcnt++;
    }
  }
  std::sort(r.begin() + 1, r.end(), std::greater<>());
  std::sort(b.begin() + 1, b.end(), std::greater<>());
  for (int i = 1; i <= rcnt; i++) {
    r[i] += r[i - 1];
  }
  for (int i = 1; i <= bcnt; i++) {
    b[i] += b[i - 1];
  }
  if (rcnt >= bcnt) {
    std::cout << b[bcnt] + r[std::min(bcnt + 1, rcnt)] << '\n';
  } else {
    std::cout << b[rcnt] + r[rcnt] << '\n';
  }
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