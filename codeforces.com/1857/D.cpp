#include <bits/stdc++.h>
#define N 200005
using namespace std;

int a[N], b[N], n, c[N];

void solve() {
  cin >> n;
  int ma = -0x7fffffff;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> b[i], c[i] = a[i] - b[i];
    ma = max(ma, c[i]);
  }
  int cnt = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (ma == c[i]) {
      ans.push_back(i + 1);
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans)
    cout << i << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}