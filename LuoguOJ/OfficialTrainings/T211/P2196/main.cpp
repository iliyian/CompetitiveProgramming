#include <bits/stdc++.h>
using namespace std;

int mine[21], ans = -1;

int a[21][21], vis[21];
vector<int> step, cur;

void dfs(int n, int sum) {
  bool end = true;
  for (int i = 1; i <= n; i++) {
    if (vis[i] || !a[n][i]) continue;
    vis[i] = true;
    end = false;
    cur.push_back(i);
    dfs(i, sum + mine[i]);
    cur.pop_back();
    vis[i] = false;
  }
  if (end && sum > ans) {
    step = cur;
    ans = sum;
  }
}

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> mine[i];
    memset(a[i], 0, sizeof(a[i]));
  }
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }
  for (int i = 1; i <= N; i++) {
    vis[i] = true;
    cur.push_back(i);
    dfs(i, mine[i]);
    cur.pop_back();
    vis[i] = false;
  }
  for (int i = step.size() - 1; i >= 0; i--)
    cout << step[i] << ' ';
  cout << '\n' << ans;
  return 0;
}