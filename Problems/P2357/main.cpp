#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  int len = ceil(sqrt(n));
  vector<int> s1(len), s2(len), a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s1[(i - 1) / len] += a[i];
  }
  auto querysum(int l, int r) {

  };
  auto add(int l, int r) {
    
  };
  for (int t = 0; t < q; t++) {
    int op, l, r, k;
    cin >> op;
    if (op == 1) {
      cin >> l >> r >> k;
      add(l, r, k);
    } else if (op == 2) {
      cin >> k;
      add(1, 1, k);
    } else if (op == 3) {
      cin >> k;
      add(1, 1, -k);
    } else if (op == 4) {
      cin >> l >> r;
      cout << querysum(l, r) << '\n';
    } else {
      cout << querysum(1, 1) << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}