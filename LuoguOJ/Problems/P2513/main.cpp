#include <bits/stdc++.h>
#define N 1001
#define mod 10000
using namespace std;

int f[N][N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  int n, k;
  cin >> n >> k;
  f[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    int sum = 0;
    for (int j = 0; j <= k; j++) {
      sum += f[i - 1][j];
      sum %= mod;
      f[i][j] = sum;
      if (j >= i - 1) {
        sum -= f[i - 1][j - i + 1];
        sum = (sum % mod + mod) % mod;
      }
    }
  }
  cout << f[n][k];
  return 0;
}