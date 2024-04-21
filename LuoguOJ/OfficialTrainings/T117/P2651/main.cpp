#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

void solve() {
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i < n; i++) {
    a[1] /= gcd(a[1], a[i]);
  }
  a[1] /= gcd(a[1], a[0]);
  if (a[1] == 1 || n == 1) {
    cout << "Yes\n";
  } else cout << "No\n";
}

int main() {
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}