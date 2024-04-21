// date: 2024-04-08 16:40:32
// tag: 单调队列优化dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    deque<int> q;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
      while (!q.empty() && q.front() < i - k) q.pop_front();      
      if (!q.empty()) {
        f[i] = f[q.front()] + (a[q.front()] <= a[i]);
      }
      while (!q.empty() && (
        f[q.back()] > f[i] || (f[q.back()] == f[i] && a[q.back()] <= a[i])))
          q.pop_back();
      q.push_back(i);
    }
    cout << f[n] << '\n';
  }
  return 0;
}