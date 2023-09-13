#include <bits/stdc++.h>
using namespace std;

int a[10000];

void solve() {
  int n, check = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], check ^= a[i];
  if (check) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}