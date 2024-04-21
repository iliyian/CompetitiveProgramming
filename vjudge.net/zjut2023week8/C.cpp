#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int n;
  cin >> n;
  vector<int> s(n + 1), a(n + 1);
  map<int, int> l, r;
  // vector<int> l(N + 1), r(N + 1);
  map<int, bool> vis;
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    a[i] = c == '1' ? 1 : -1;
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 0; i <= n; i++) {
    if (!vis[s[i]]) l[s[i]] = i, vis[s[i]] = true;
    r[s[i]] = i;
  }
  int ans = -1;
  for (auto &[x, y] : l) {
    ans = max(ans, r[x] - y);
  } 
  cout << ans;
}