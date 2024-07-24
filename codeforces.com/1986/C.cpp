#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  string s, c;
  cin >> n >> m >> s;
  vector<int> idx(m + 1);
  vector<int> cnt(n + 1);
  for (int i = 1; i <= m; i++) {
    cin >> idx[i];
    idx[i]--;
    cnt[idx[i]]++;
  }
  cin >> c;
  sort(idx.begin() + 1, idx.end());
  sort(c.begin(), c.end());
  idx.erase(unique(idx.begin() + 1, idx.end()), idx.end());

  int r = c.size() - 1, l = 0;
  for (int i = 1; i < idx.size(); i++) {
    for (int j = 0; j < cnt[idx[i]] - 1; j++) {
      s[idx[i]] = c[r--];
    }
    s[idx[i]] = c[l++];
  }
  cout << s << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}