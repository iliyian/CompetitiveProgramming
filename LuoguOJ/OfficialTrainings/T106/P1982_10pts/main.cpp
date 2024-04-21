#include <bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;

array<long long, 1000000> a, b, c, sum;


int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, mod;
  cin >> n >> mod;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) sum[i] = sum[i - 1] + a[i];
    else sum[i] = a[i];
  }
  b.fill(-inf);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++)
      b[i] = max(b[i], sum[i] - sum[j] + a[j]);
  }
  c.fill(-inf);
  c[0] = b[0];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      c[i] = max(c[i], b[j] + c[j]);
  cout << *max_element(c.begin(), c.begin() + n) % mod;
  return 0;
}