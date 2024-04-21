#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 1005
using namespace std;

vector<pair<int, int>> v;
int f[N], n;

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    v.push_back({s, t});
  }
  sort(v.begin(), v.end());
  int ans = 0;
  fill(f, f + n, 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      f[i] = max(f[i], f[j] + (v[j].second <= v[i].first));
      ans = max(ans, f[i]);
    }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("2.in", "r", stdin);
  freopen("2.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}