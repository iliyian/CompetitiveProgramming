#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int t, p;
};

void solve() {
  int n, m, h;
  cin >> n >> m >> h;

  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    vector<int> probs;
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      probs.push_back(t);
    }
    sort(probs.begin(), probs.end());
    int p = 0, t = 0, rt = 0;
    for (int j = 0; j < m; j++) {
      if (rt + probs[j] <= h) {
        p += probs[j] + p;
        rt += probs[j];
        t++;
      }
    }
    v.push_back({t, p});
  }

  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](const int &x, const int &y) {
    auto &a = v[x], &b = v[y];
    if (a.first == b.first && a.second == b.second) return !x;
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  });
  for (int i = 0; i < n; i++) {
    if (id[i] == 0) {
      cout << i + 1 << '\n';
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}