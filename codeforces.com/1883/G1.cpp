#include <bits/stdc++.h>
using namespace std;

int a[100001], b[100001];
bitset<100001> vis;
map<int, int> cnt;

void solve() {
  int n, m;
  cin >> n >> m;
  a[0] = m;
  for (int i = 1; i < n; i++)
    cin >> a[i];
  cnt.clear();
  for (int i = 0; i < n; i++)
    cin >> b[i], cnt[b[i]]++;

  // sort(b, b + n);
  // vis.reset();

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto p = cnt.upper_bound(a[i]);
    if (p == cnt.end()) ans++;
    else {
      while (p->second == 0) p++;
      p->second--;
    }
  }
  cout << ans << '\n';
}

int main() {
  freopen("G1.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}