#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int mi = 0x3f3f3f3f3f3f3f3f;
  vector<int> sec;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<int> a;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(), a.end());
    mi = min(mi, a.front());
    sec.push_back(a[1]);
  }
  sort(sec.begin(), sec.end(), greater<int>());
  int sum = mi;
  for (int i = 0; i < sec.size() - 1; i++)
    sum += sec[i];
  cout << sum << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}