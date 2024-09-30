#include <bits/stdc++.h>
#define N 105
using namespace std;

int a[N];

void solve() {
  int n, k;
  cin >> n >> k;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (is_sorted(a + 1, a + 1 + n) || k >= 2) cout << "YES";
  else cout << "NO";
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}