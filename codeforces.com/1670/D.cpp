// date: 2024-04-30 16:02:02
// tag: 数学，二分

#include <bits/stdc++.h>
#define int long long
#define N 100000
using namespace std;

vector<int> a(N + 1), s(N + 1);

void solve() {
  int n;
  cin >> n;
  cout << lower_bound(s.begin() + 1, s.end(), n) - s.begin() << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  for (int i = 2; i <= N; i++) {
    if (i % 3 == 1) a[i] = a[i - 1];
    else a[i] = a[i - 1] + 1;
  }
  for (int i = 2; i <= N; i++) {
    s[i] = s[i - 1] + a[i] * 2;
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}