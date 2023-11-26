#include <bits/stdc++.h>
#define N 200001
using namespace std;

int a[N], b[N], ans[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  iota(b, b + n, 0);
  sort(b, b + n, [](const int &x, const int &y) {
    return a[x] > a[y];
  });
  for (int i = 0; i < n; i++)
    ans[b[i]] = i + 1;
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}