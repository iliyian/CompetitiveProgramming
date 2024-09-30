#include <bits/stdc++.h>
#define N 200001
using namespace std;

int a[N];

void solve() {
  int n;
  cin >> n;
  int minv = 0x3f3f3f3f, mini = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < minv) {
      minv = a[i];
      mini = i;
    }
  }
  for (int i = mini + 1; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << mini << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}