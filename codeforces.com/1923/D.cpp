#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> ans(n + 1, inf);
  for (int t = 0; t < 2; t++) {
    vector<bool> f(n + 1);
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + a[i];
    }
    int pos = -1;
    for (int i = n; i >= 1; i--) {
      if (a[i] != a[n]) {
        pos = i;
        break;
      }
    }

    for (int i = 1; i <= n; i++) {
      int x = s[i] + a[i];
      int id = upper_bound(s.begin() + i + 1, s.end(), x) - s.begin() - i;
      if (id + i > n || i == pos && i < n && a[i] > a[i + 1] || pos == -1) {
        continue;
      }
      int idx = t ? n - i + 1 : i;
      ans[idx] = min(ans[idx], id);
    }
    reverse(a.begin() + 1, a.end());
  }
  for (int i = 1; i <= n; i++) {
    int x = ans[i];
    cout << (x == inf ? -1 : x) << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}