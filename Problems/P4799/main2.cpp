#include <bits/stdc++.h>
using namespace std;

int N;
long long a[40], M, ans = 0;

void dfs(int cur, long long sum, int lim, vector<long long> &v) {
  if (sum > M) return;
  v.push_back(sum);
  for (int i = cur; i < lim; i++) {
    dfs(i + 1, sum + a[i], lim, v);
  }
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
  sort(va.begin(), va.end());
  for (int i = 0; i < vb.size(); i++)
    ans += upper_bound(va.begin(), va.end(), M - vb[i]) - va.begin();
    // <= M - vb[i];
  cout << ans;
  return 0;
}