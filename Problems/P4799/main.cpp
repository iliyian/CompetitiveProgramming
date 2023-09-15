// 区间的开闭性格外重要
// 务必注意爆 int

#include <bits/stdc++.h>
using namespace std;

int N;
long long a[40], M;

void dfs(int cur, long long sum, int lim, vector<long long> &v) {
  if (sum > M) return;
  if (cur >= lim) {
    v.push_back(sum);
    return;
  }
  dfs(cur + 1, sum, lim, v);
  dfs(cur + 1, sum + a[cur], lim, v);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> a[i];
  vector<long long> va, vb;
  dfs(0, 0, N / 2, va);
  dfs(N / 2, 0, N, vb);
  // []
  sort(va.begin(), va.end());
  long long ans = 0;
  for (int i = 0; i < vb.size(); i++)
    ans += upper_bound(va.begin(), va.end(), M - vb[i]) - va.begin();
    // <= M - vb[i];
  cout << ans;
  return 0;
}