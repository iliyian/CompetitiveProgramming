#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int n, mink;
  cin >> n >> mink;
  vector<int> a(n + 1), sum(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i], sum[i] = sum[i - 1] + a[i];
  double ans = -1;
  for (int k = mink; k <= n; k++)
    for (int l = 1; l <= n - k + 1; l++) {
      int r = l + k - 1;
      ans = max(ans, double(sum[r] - sum[l - 1]) / k);
    }
  cout << fixed << setprecision(15) << ans;
}