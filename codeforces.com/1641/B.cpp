#include <bits/stdc++.h>
#define int long long
#define N 500
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> prv;
  vector<int> nxt(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!prv[a[i]]) {
      prv[a[i]] = i;
    } else {
      nxt[prv[a[i]]] = i;
      prv[a[i]] = 0;
    }
  }
  bitset<N + 1> rm;
  vector<pair<int, int>> add;
  int pre = 0, rmcnt = 0;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (prv[a[i]]) {
      cout << -1 << '\n';
      cout << '\n';
      return;
    }
    if (!nxt[i]) continue;
    for (int j = i + 1; j < nxt[i]; j++) {
      a[]
    }
  }
  cout << add.size() << '\n';
  for (auto [k, v] : add) {
    cout << k << ' ' << v << '\n';
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << "\n\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}