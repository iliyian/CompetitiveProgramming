#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

signed main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k, lcm = 1;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    lcm = lcm * a / gcd(lcm, a) % k;
  }
  cout << (lcm % k ? "No" : "Yes");
  return 0;
}