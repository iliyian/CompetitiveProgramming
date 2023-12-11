// date: 2023:12/9
// tag: fuck 离散化，fuck差分

#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

int l[N], r[N], b[N], a[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("I.in", "r", stdin);
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    v.push_back({l, 1});
    v.push_back({r + 1, -1});
  }
  sort(v.begin(), v.end());
  int prev = 0, cnt = 0;
  map<int, int> ans;
  for (auto [x, y] : v) {
    // perfect cover
    ans[cnt] += x - prev;
    cnt += y;
    prev = x;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}