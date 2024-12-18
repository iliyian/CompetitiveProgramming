#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, q;
  cin >> n >> q;
  multiset<int> s;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }
  for (int i = 0; i < q; i++) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      auto it = s.lower_bound(x);
      if (it != s.end() && *it == x) s.erase(it);
      else {
        cout << -1 << '\n';
        continue;
      }
    } else s.insert(x);
    cout << 2 * (*(s.rbegin()) - *s.begin()) << '\n';
  }
  return 0;
}