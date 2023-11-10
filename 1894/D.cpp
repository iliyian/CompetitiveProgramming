#include <bits/stdc++.h>
#define N 200001
using namespace std;

int a[N], b[N];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];
  sort(b + 1, b + 1 + m, greater<int>());
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    while (cur <= m && b[cur] >= a[i]) {
      cout << b[cur++] << ' ';
    }
    cout << a[i] << ' ';
  }
  while (cur <= m)
    cout << b[cur++] << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("D.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}