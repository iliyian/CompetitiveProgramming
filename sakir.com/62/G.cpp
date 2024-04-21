#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int n, k, p;
  cin >> n >> k >> p;
  vector<int> t(n + 1), d(n + 1), fst(k + 1), lst(k + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    if (!fst[t[i]]) {
      fst[t[i]] = i;
    }
    lst[t[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  int ans = 0;
  vector<int> dif(n + 2);
  for (int i = 1; i <= k; i++) {
    int l = fst[i], r = lst[i];
    if (r - l + 1 >= p) {
      dif[l]++, dif[r + 1]--;
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    dif[i] += dif[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    if (dif[i]) {
      ans += d[i];
    }
  }
  cout << ans << '\n';

  return 0;
}