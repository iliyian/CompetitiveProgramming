#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  set<char> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    s.insert(c);
    ans += s.size();
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}