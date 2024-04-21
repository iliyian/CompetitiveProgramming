// a太容易爆了，务必多测试几个边界值

#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("data.in", "r", stdin);
  long long a, b, p, ans = 1;
  cin >> a >> b >> p;
  cout << a << "^" << b << " mod " << p << "=";
  while (b) {
    a = a % p;
    if (b & 1) ans *= a, ans %= p;
    a *= a;
    b >>= 1;
  }
  cout << ans;
  return 0;
}