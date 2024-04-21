#include <bits/stdc++.h>
using namespace std;

long long a[100005];

int main() {
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] + a[i + 1] > m) {
      long long rest = a[i + 1] + a[i] - m;
      ans += rest;
      if (a[i + 1] >= rest) {
        a[i + 1] -= rest;
      } else {
        rest -= a[i + 1];
        a[i] -= rest;
        a[i + 1] = 0;
      }
    }
  }
  cout << ans;
  return 0;
}