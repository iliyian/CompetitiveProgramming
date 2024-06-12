// date: 2024-06-09 19:25:37
// tag: 概率

#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rd(random_device{}());

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), pos(n + 1), p(n + 1), q(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  iota(q.begin() + 1, q.end(), 1);
  for (int t = 1; t <= 1000; t++) {
    shuffle(q.begin() + 1, q.end(), rd);
    bool f = true;
    for (int i = 1; i <= n; i++) {
      if (q[i] == i || q[i] == pos[i]) {
        f = false;
        break;
      }
    }
    if (f) {
      cout << "Possible\n";
      for (int i = 1; i <= n; i++) {
        p[q[i]] = pos[i];
      }
      for (int i = 1; i <= n; i++) {
        cout << p[i] << ' ';
      }
      cout << '\n';
      for (int i = 1; i <= n; i++) {
        cout << q[i] << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << "Impossible\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}