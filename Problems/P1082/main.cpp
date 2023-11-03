#include <bits/stdc++.h>
#define int long long
using namespace std;

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("data.in", "r", stdin);
  int a, b, x, y;
  cin >> a >> b;
  exgcd(a, b, x, y);
  x = (x % b + b) % b;
  cout << x;
  return 0;
}