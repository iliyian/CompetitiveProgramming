#include <bits/stdc++.h>
#define N 200005
using namespace std;

int a[N];

void solve() {
  int n, m;
  cin >> n >> m;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) s.insert(i);
  }
  for (int i = 0; i < m; i++) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      if ((x - s.size()) & 1) {
        if (s.empty()) {
          cout << "NO\n";
          continue;
        }
        int sum1 = (n - *s.begin()) * 2 - (s.size() - 1);
        int sum2 = (*s.rbegin() - 1) * 2 - (s.size() - 1);
        if (x > max(sum1, sum2)) cout << "NO\n";
        else cout << "YES\n";
      } else {
        if (s.size() + 2 * (n - s.size()) < x) cout << "NO\n";
        else cout << "YES\n";
      }
    } else {
      cin >> a[x];
      s.erase(x);
      if (a[x] == 1) s.insert(x);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}