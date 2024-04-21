#include <bits/stdc++.h>
using namespace std;

bitset<10086> vis;

void dfs(int n, int cnt) {
  if (!n) {
    vis[cnt] = true;
    return;
  }
  for (int r = n; r >= 1; r--)
    dfs(n - r, r * (n - r) + cnt); // 其他线与已确定的平行线必定有交点，妙啊
}

int main() {
  int n;
  cin >> n;
  dfs(n, 0);
  cout << vis.count();
  return 0;
}