// long long 烦死了

#include <bits/stdc++.h>
using namespace std;

int a[1000], N, C;
long long ans = -1, sums[1000];

void dfs(int last, long long sum) {
  if (sum > C) return;
  if (sum + sums[last] <= C) {
    sum += sums[last];
    ans = max(ans, sum);
    return;
  }
  ans = max(ans, sum);
  for (int i = last; i >= 0; i--)
    dfs(i - 1, sum + a[i]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  memset(sums, 0, sizeof(sums));
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (i) sums[i] = sums[i-1] + a[i];
    else sums[i] = a[i];
  }
  dfs(N - 1, 0);
  cout << ans;
  return 0;
}