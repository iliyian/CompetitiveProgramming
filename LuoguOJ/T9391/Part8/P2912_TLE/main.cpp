#include <bits/stdc++.h>
using namespace std;

int nxt[100001];
bitset<100001> vis;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
  }
  for (int i = 1; i <= n; i++) {
    int cnt = 0, cur = i;
    while (!vis[cur]) {
      vis[cur] = true;
      cnt++;
      cur = nxt[cur];
    }
    cout << cnt << '\n';
    vis.reset();
  }
  return 0;
}