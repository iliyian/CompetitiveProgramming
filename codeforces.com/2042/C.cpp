#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::priority_queue<int> q;
  std::vector<int> a(n + 2);
  for (int i = n; i >= 1; i--) {
    a[i] = a[i + 1] + (str[i] == '1' ? 1 : -1);
    if (i > 1) {
      q.push(a[i]);
    }
  }
  int sum = 0, ans = 0;
  while (sum < k && !q.empty()) {
    int u = q.top(); q.pop();
    sum += u;
    ans++;
  }
  if (sum < k) {
    std::cout << -1 << '\n';
  } else {
    std::cout << ans + 1 << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}