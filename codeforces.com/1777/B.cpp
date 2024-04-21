#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

int a[100001];

void solve() {
  int n;
  cin >> n;
  cout << n * (n - 1) % mod * a[n] % mod << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t;
  cin >> t;
  a[1] = 1;
  for (int i = 2; i <= 100000; i++)
    a[i] = a[i - 1] * i % mod;
  while (t--) solve();
  return 0;
}