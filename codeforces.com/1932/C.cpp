#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  string str;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> str;
  str = '#' + str;
  vector<int> vec;
  int l = 1, r = n;
  for (int t = 1; t <= n; t++) {
    if (str[t] == 'L') {
      vec.push_back(a[l++]);
    } else {
      vec.push_back(a[r--]);
    }
  }
  int cur = 1;
  vector<int> ans;
  reverse(vec.begin(), vec.end());
  for (auto v : vec) {
    cur = cur * (v % m) % m;
    ans.push_back(cur);
  }
  reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
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