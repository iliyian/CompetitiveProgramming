#include <bits/stdc++.h>
using namespace std;

int a[50000];

int main() {
  int n, k, maxn = -1;
  cin >> n >> k;
  map<int, int> m;
  for (int i = 0; i < n; i++)
    cin >> a[i], m[a[i]]++, maxn = max(maxn, a[i]);
  sort(a, a + n);
  int ans = 0;
  for (int i = 1; i <= maxn - k; i++) {
    ans += a[i];
    if (i > k)
  }
}