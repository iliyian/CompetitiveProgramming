// date: 2024-08-02 12:39:10
// tag: 反悔贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (!q.empty() && q.top() < a[i]) {
      ans += a[i] - q.top(); q.pop();
      q.push(a[i]);
    }
    q.push(a[i]);
  }
  std::cout << ans << '\n';

  return 0;
}