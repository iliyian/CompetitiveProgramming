#include <bits/stdc++.h>
#define N 100005
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<char> a(n);
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  char minv = 'z' + 1;
  for (int i = n - 1; i >= 1; i--) {
    minv = min(minv, a[i]);
    if (a[i - 1] > minv) 
  }

                                               
  // int leftmost = 0, rightmost = n - 1, ans = 0;
  // bitset<N> vis;
  // for (int i = 0; i < n; i++) {
  //   int len = 0, cur = id[i];
  //   vector<int> idx;
  //   for (int j = id[i] + 1; j < n; j++) {
  //     if (a[j] < a[j - 1]) len++, idx.push_back(j);
  //     else len = 1, idx.clear();
  //   }
  //   if (!idx.empty() && idx.back() != id[rightmost]) {
  //     cout << -1 << '\n';
  //     return;
  //   }
  //   for (int j : idx) vis[j] = true;
  //   vis[id[i]] = true;
  //   while (rightmost > i && vis[id[rightmost]]) rightmost--;
  //   ans += idx.size();
  // }
  // cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}