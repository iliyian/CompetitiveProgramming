#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
bitset<50> vis1, vis2, vis;

void dfs(int cur) {
  if (cur == n) {
    ans++;
    return;
  }
  for (int i = 0; i < n; i++)
    if (!vis[i] && !vis1[cur + i] && !vis2[cur - i + n]) {
      vis[i] = vis1[cur + i] = vis2[cur - i + n] = true;
      dfs(cur + 1);
      vis[i] = vis1[cur + i] = vis2[cur - i + n] = false;
    }
}

void solve() {
  while (cin >> n) {
    vis1.reset(), vis2.reset(), vis.reset();
    ans = 0;
    dfs(0);
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("2.in", "r", stdin);
  freopen("2.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}