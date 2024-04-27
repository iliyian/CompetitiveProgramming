#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("J.in", "r", stdin);
  freopen("J.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int L, q;
  cin >> L >> q;
  for (int _ = 1; _ <= q; _++) {
    int l, r;
    cin >> l >> r;
    if (l > r) swap(l, r);
    int ans = r - l;
  }

  return 0;
}