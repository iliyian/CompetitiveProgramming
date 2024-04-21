#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  str = '#' + str;
  vector<int> i1(n + 1), i0(n + 1);
  int x = 1;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') {
      x = i;
    }
    i0[i] = x;
  }
  for (int i = n; i >= 1; i--) {
    if (str[i] == '1') {
      x = i;
    }
    i1[i] = x;
  }
  map<pair<int, int>, int> cnt;
  for (int t = 0; t < m; t++) {
    int l, r;
    cin >> l >> r;
    if (str[r] == '1') {
      r = i0[r];
    }
    if (str[l] == '0') {
      l = i1[l];
    }
    if (l >= r) {
      l = 0, r = 0;
    }
    cnt[{l, r}]++;
  }
  cout << cnt.size() << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}