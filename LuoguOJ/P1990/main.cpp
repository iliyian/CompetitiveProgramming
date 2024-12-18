// 不妨画图，就近创新

#include <bits/stdc++.h>
#define mod 10000
using namespace std;

int f[1000001], g[1000001];

int main() {
  int N;
  cin >> N;
  f[0] = 1;
  f[1] = 1, f[2] = 3, f[3] = 5;
  g[1] = 1;
  for (int i = 2; i <= N; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % mod + g[i - 2] * 2 % mod;
    g[i] = g[i - 1] % mod + f[i - 1] % mod;
  }
  cout << f[N] % mod;
  return 0;
}