// double-pointer

#include <bits/stdc++.h>
#define N 50002
using namespace std;

int a[N], c[N];

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  int ans = 0, r = 2, leftmax = 0;
  for (int i = 1; i <= n; i++) {
    while (a[r] <= a[i] + k && r <= n) r++;
    c[r] = max(c[r], r - i);
    leftmax = max(leftmax, c[i]);
    ans = max(ans, leftmax + r - i);
  }
  cout << ans;
  return 0;
}