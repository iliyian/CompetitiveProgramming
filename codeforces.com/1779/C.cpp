// date: 2024-06-15 23:48:10
// tag: 妙，全是数学

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  priority_queue<int, vector<int>, greater<int>> leq;
  priority_queue<int, vector<int>, less<int>> geq;
  int ans = 0, sum = 0;
  for (int i = m + 1; i <= n; i++) {
    leq.push(a[i]);
    sum += a[i];
    if (sum < 0) {
      ans++;
      sum -= leq.top() * 2;
      leq.pop();
    }
  } 
  sum = 0;
  for (int i = m; i > 1; i--) {
    geq.push(a[i]);
    sum += a[i];
    if (sum > 0) {
      ans++;
      sum -= geq.top() * 2;
      geq.pop();
    }
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}