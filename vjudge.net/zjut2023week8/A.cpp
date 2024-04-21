#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), s1(n + 1), s2(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i], s1[i] = s1[i - 1] + a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i], s2[i] = s2[i - 1] + a[i] * b[i];
  int ans = -1;
  for (int l = 1; l <= n - k + 1; l++) {
    int r = l + k - 1;
    int d = s1[r] - s1[l - 1] - (s2[r] - s2[l - 1]);
    int sum = s2[n] + d; // ?
    ans = max(ans, sum);
  }
  cout << ans;
}