// date: 2024-05-20 21:19:50
// tag: 单调栈，连通性

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), x(n + 1), y(n + 1), id(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    x[i] = a[i] - i, y[i] = i - b[i];
    id[i] = i;
  }
  sort(id.begin() + 1, id.end(), [&](const int &_x, const int &_y) {
    return x[_x] < x[_y];
  });

  // for (int i = 1; i <= n; i++) {
  //   cerr << format("{} {} {}", id[i], x[id[i]], y[id[i]]) << '\n';
  // }

  stack<int> s;
  for (int i = 1; i <= n; i++) {
    if (s.empty() || y[s.top()] > y[id[i]]) {
      s.push(id[i]);
    } else {
      int tp = s.top(); s.pop();
      while (!s.empty() && y[s.top()] <= y[id[i]]) {
        s.pop();
      }
      s.push(tp);
    }
  }
  cout << s.size() << '\n';

  return 0;
}