// date: 2023/12/30 20:50:26
// tag: 榫卯的互补的美感，d根本不需要动态统计什么的，d的影响很小
// 在于找到看似变幻的事物中的不变量

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  priority_queue<int, vector<int>, greater<int>> q;
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x > 0) sum += x, q.push(x);
    while (q.size() > m) sum -= q.top(), q.pop();
    ans = max(ans, sum - d * i);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}