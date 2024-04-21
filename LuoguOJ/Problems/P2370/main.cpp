// dp数组+1,存值数组不加
// 二分mid +- 1更激进，必须激进

#include <bits/stdc++.h>
using namespace std;

int w[1000], v[1000], dp[1001], n, p, s, maxw = -1;

bool check(int L) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++)
    if (L >= w[i])
      for (int j = s; j >= w[i]; j--)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  return dp[s] >= p;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> p >> s;
  for (int i = 0; i < n; i++)
    cin >> w[i] >> v[i], maxw = max(maxw, w[i]);
  int l = 1, r = maxw;
  bool f = false;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) r = mid - 1, f = true;
    else l = mid + 1;
  }
  if (f) cout << l;
  else cout << "No Solution!";
  return 0;
}