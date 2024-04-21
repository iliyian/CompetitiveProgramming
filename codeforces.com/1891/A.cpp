#include <bits/stdc++.h>
using namespace std;

int a[21], b[21];

bool check(int x) {
  return x == 1 || x == 2 || x == 4 || x == 8 || x == 16;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], b[i] = a[i] - a[i - 1];
  for (int j = n; j >= 1; j--) {
    if (b[j] < 0 & !check(j - 1)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}