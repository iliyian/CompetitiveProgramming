// date: 2025-05-14 23:48:02
// tag: 暴力水题，乘法很容易跟log扯上关系，于是就是log级别的暴力了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), s(n + 1);
  std::vector<int> b = {0};
  a[0] = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s[i] = s[i - 1] + a[i];
    if (a[i] > 1) {
      b.push_back(i);
    }
  }
  if (b.size() <= 2) {
    std::cout << "1 1" << '\n';
    return;
  }
  std::vector<int> mul(b.size());
  mul[0] = 1;
  for (int i = 1; i < b.size(); i++) {
    mul[i] = mul[i - 1] * a[b[i]];
    if (mul[i] > 1e9) {
      std::cout << b[1] << ' ' << b.back() << '\n';
      return;
    }
  }
  int ans = s[n], ansl = 1, ansr = 1;
  for (int i = 1; i < b.size(); i++) {
    for (int j = i + 1; j < b.size(); j++) {
      int cur = s[n] - (s[b[j]] - s[b[i] - 1]) + mul[j] / mul[i - 1];
      if (cur > ans) {
        ansl = b[i], ansr = b[j];
        ans = cur;
      }
    }
  }
  std::cout << ansl << ' ' << ansr << '\n';
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