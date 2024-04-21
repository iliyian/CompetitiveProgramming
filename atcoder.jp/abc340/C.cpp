#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, int> ans;

int dfs(int x) {
  if (ans[x]) return ans[x];
  if (x == 1) return 0;
  return ans[x] = x + dfs(ceil(x / 2.0)) + dfs(floor(x / 2.0));
}

void solve() {
  int n;
  cin >> n;
  cout << dfs(n) << '\n';
}
// 101
// 5+2+3+2

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("C.in", "r", stdin);
  // freopen("C.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}