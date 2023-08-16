#include <bits/stdc++.h>
using namespace std;

int needs[25], has[15][25], curhas[25], v, g, ans = 0x7fffffff;
vector<int> ansv, cura;

void use(int n, int s) {
  for (int i = 0; i < v; i++)
    curhas[i] += s * has[n][i];
}

bool check() {
  for (int i = 0; i < v; i++)
    if (curhas[i] < needs[i])
      return false;
  return true;
}

void dfs(int cur, int cnt) {
  if (cnt >= ans) return;
  if (check()) {
    ans = cnt;
    ansv = cura;
    return;
  }
  for (int i = cur + 1; i < g; i++) {
    use(i, 1);
    cura.push_back(i);
    dfs(i, cnt + 1);
    cura.pop_back();
    use(i, -1);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> v;
  for (int i = 0; i < v; i++) {
    cin >> needs[i];
  }
  cin >> g;
  for (int i = 0; i < g; i++)
    for (int j = 0; j < v; j++)
      cin >> has[i][j];
  for (int i = 0; i < g; i++) {
    use(i, 1);
    cura.push_back(i);
    dfs(i, 1);
    cura.pop_back();
    use(i, -1);
  }
  cout << ans << ' ';
  for (auto i : ansv)
    cout << i + 1 << ' ';
  return 0;
}