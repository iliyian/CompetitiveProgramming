#include<bits/stdc++.h>
#define N 200005
using namespace std;

int a[N], d[N];

struct Node {
  int x, y, d;
  bool operator < (const Node &b) const {
    return d < b.d;
  }
};

void solve() {
  int n;
  cin >> n;
  int maxx = -1, maxy = 1, maxd = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int len = unique(a + 1, a + 1 + n) - a - 1;
  if (len <= 3) {
    cout << 0 << '\n';
    return;
  }
  priority_queue<Node> q;
  for (int i = 1; i < len - 1; i++) {
    q.push({i, i + 1, abs(a[i] - a[i + 1])});
  }
  q.pop();
  int d = q.top().d;
  cout << (d - 1) / 2 + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}