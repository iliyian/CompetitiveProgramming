#include <bits/stdc++.h>
#define N 200001
using namespace std;

int a[N];

void solve() {
  int n;
  cin >> n;
  int mex = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0 && a[i]) mex = 0;
    if (i > 0 && a[i] != a[i - 1] + 1) mex = a[i - 1] + 1;
  }
  if (mex == -1) mex = a[n - 1] + 1;
  cout << mex << endl;
  int x;
  cin >> x;
  while (x != -1) {
    cout << x << endl;
    cin >> x;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}