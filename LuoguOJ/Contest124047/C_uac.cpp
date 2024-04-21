#include <bits/stdc++.h>
using namespace std;

multiset<int> ks, bs;
multiset<pair<int, int>> kbs;

int main() {
  ios::sync_with_stdio(false); cin.tie();
  freopen("data.in", "r", stdin);
  int n, kcnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int op, k, b;
    cin >> op >> k >> b;
    if (op == 1) {
      ks.insert(k);
      kbs.insert({k, b});
    } else if (op == 2) {
      int ans = ks.size() - ks.count(k);
      cout << ans << '\n';
    } else {
      kbs.erase({k, b});
      if (ks.erase(k)) {
        auto it = kbs.upper_bound({k, 0x7fffffff});
        while (it != kbs.end()) {
          kbs.erase(*it);
          it = kbs.upper_bound({k, 0x7fffffff});
        }
        it = kbs.lower_bound({k, -0x7fffffff});
        while (it != kbs.end()) {
          --it;
          kbs.erase(*it);
          it = kbs.lower_bound({k, -0x7fffffff});
        }
      }
    }
  }
  return 0;
}