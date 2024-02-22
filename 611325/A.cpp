#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

int h(const Node &x, const Node &y) {
  for (int j = 1; j <= n + 1; j++) {
    for (int i = 1; i <= 3; i++) {

    }
  }
};

struct Node {
  int dis;
  vector<vector<int>> a;
  bool operator < (const Node &b) const {
    return dis + h(*this) > b.dis + h(b);
  }
};

void solve() {
  cin >> n;
  vector<vector<int>> a(4, vector<int>(n + 2));
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  priority_queue<Node> q;
  while (!q.empty()) {
    Node node = q.top(); q.pop();

  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}