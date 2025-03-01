#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), rs(n + 1), ls(n + 1), pr(n + 1);
  std::stack<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int prv = 0;
    while (!s.empty() && a[s.top()] < a[i]) {
      prv = s.top();
      pr[s.top()] = i;
      s.pop();
    }
    if (!s.empty()) rs[s.top()] = i;
    if (prv) ls[i] = prv;
    s.push(i);
  }
  int ansl = 0, ansr = 0;
  for (int i = 1; i <= n; i++) {
    ansl ^= i * (ls[i] + 1);
    ansr ^= i * (rs[i] + 1);
    std::cerr << ls[i] << ' ' << rs[i] << ' ' << pr[i] << '\n';
  }
  std::cout << ansl << ' ' << ansr << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}