#include <bits/stdc++.h>
#define N 200005
using namespace std;

bitset<N> vis;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  vis.reset();
  vector<pair<int, int>> c;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int alen = unique(a.begin(), a.end()) - a.begin();
  int blen = unique(b.begin(), b.end()) - b.begin();

  for (int i = 0; i < alen; i++)
    c.push_back({a[i], 1});
  for (int i = 0; i < blen; i++)
    c.push_back({b[i], 0});
  
  sort(c.begin(), c.end());
  int acnt = 0, bcnt = 0, cur = 1;
  for (int i = 0; i < c.size(); i++) {
    if (c[i].first > k) break;
    if (cur == c[i].first) cur++;
    acnt += c[i].second == 1, bcnt += c[i].second == 0;
  }
  if (acnt < k / 2 || bcnt < k / 2 || cur != k + 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}