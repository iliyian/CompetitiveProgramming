#include <bits/stdc++.h>
#define N 105
#define int long long
using namespace std;

int x[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) {
    int a, b, n;
    cin >> a >> b >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++)
      cin >> x[i], q.push(x[i]);
    sort(x, x + n);
    int ans = 0;
    while (!q.empty()) {
      while (!q.empty() && b + q.top() <= a) {
        b += q.top(); q.pop();
      }
      if (b == 1) {
        b += q.top(); q.pop();
        b = min(b, a);
      }
      ans += b - 1;
      b = 1;
    }
    cout << ans + 1 << '\n';
  }
}