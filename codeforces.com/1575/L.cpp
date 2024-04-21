// date: 2024-04-13 16:38:33
// tag: 二维数点

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int x, y;
  bool operator < (const Node &b) const {
    return tie(x, y) < tie(b.x, b.y);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("L.in", "r", stdin);
  freopen("L.out", "w", stdout);

  int n;
  cin >> n;
  vector<Node> a;
  vector<int> b(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i + 1 - x >= 0) {
      a.push_back({i + 1 - x, x});
    }
  }
  sort(a.begin(), a.end());
  int len = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i].y > b[len]) b[++len] = a[i].y;
    else *lower_bound(b.begin(), b.begin() + len, a[i].y) = a[i].y;
  }
  cout << len << '\n';

  return 0;
}