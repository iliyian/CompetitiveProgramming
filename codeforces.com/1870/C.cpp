#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), id(n), v(n);
  fill(v.begin(), v.end(), n);
  iota(id.begin(), id.end(), 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(id.begin(), id.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });
  int leftmost = 0, rightmost = n - 1, cnt = 0;
  bitset<100002> vis;
  for (int i = 0; i < n; i++) {
    vis[id[i]] = true;
    v[id[i]] = max(0, rightmost - leftmost + 1);
    while (leftmost <= 100001 && vis[leftmost]) leftmost++;
    while (rightmost >= 0 && vis[rightmost]) rightmost--;
  }
  vector<int> ans(k + 1);
  for (int i = 0; i < n; i++)
    if (!ans[a[id[i]]])
      ans[a[id[i]]] = v[id[i]] * 2;
  for (int i = 1; i <= k; i++) {
    cout << ans[i] << " \n"[i == k];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}