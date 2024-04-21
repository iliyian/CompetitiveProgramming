// gcd(k/b, k/a) == 1 <=> lcm(a,b) == k

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int t = 0; t < n; t++) {
    int a0, a1, b0, b1, ans = 0;
    cin >> a0 >> a1 >> b0 >> b1;
    for (int i = 1; i * i <= b1; i++) {
      if (b1 % i == 0) {
        if (i % a1 == 0 && gcd(b1 / b0, b1 / i) == 1 && gcd(i / a1, a0 / a1) == 1)
          ans++;
        int y = b1 / i;
        if (y == i) continue;
        if (y % a1 == 0 && gcd(b1 / b0, b1 / y) == 1 && gcd(y / a1, a0 / a1) == 1)
          ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}