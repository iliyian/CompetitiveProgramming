// 一亿离谱得只能开map
// unordered_map过了map没过的，顺便洛谷机器性能nb

#include <bits/stdc++.h>
using namespace std;

pair<int, int> neqs[1000005];

unordered_map<int, int> pa;

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    pa.clear();
    int n, neqc = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x, y, e;
      cin >> x >> y >> e;
      if (!pa[x]) pa[x] = x;
      if (!pa[y]) pa[y] = y;
      if (e) {
        pa[find(x)] = find(y);
      }
      else neqs[neqc++] = {x, y};
    }
    bool f = true;
    for (int i = 0; i < neqc; i++) {
      if (find(neqs[i].first) == find(neqs[i].second)) {
        cout << "NO\n"; f = false;
        break;
      }
    }
    if (f) cout << "YES\n";
  }
  return 0;
}