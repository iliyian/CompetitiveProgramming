#include <bits/stdc++.h>
using namespace std;

char a[1001][1001];
int f[1001][1001];

struct Node {
  int cnt, h;
};

int ans = 0, n, m;

void update(int r) {
  stack<Node> s;
  s.push({1, f[r][1]});
  for (int i = 2; i <= m; i++) {
    int cnt = 0, h = f[r][i];
    while (!s.empty() && s.top().h >= h) {
      cnt += s.top().cnt;
      ans = max(ans, cnt * s.top().h);
      s.pop();
    }
    s.push({cnt + 1, h});
  }

  int cnt = 0;
  while (!s.empty()) {
    cnt += s.top().cnt;
    ans = max(ans, s.top().h * cnt);
    s.pop();
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      f[i][j] = a[i][j] == 'R' ? 0 : f[i - 1][j] + 1;
    }
  for (int i = 1; i <= n; i++)
    update(i);

  cout << ans * 3;
  return 0;
}