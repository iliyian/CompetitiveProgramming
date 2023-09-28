#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v, x;
  bool operator < (const Node &b) const {
    return v < b.v;
  }
};

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  priority_queue<Node> q;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    q.push({a, i});
    if (i >= k) {
      while (!q.empty() && q.top().x < i - k + 1) q.pop();
      cout << q.top().v << '\n';
    }
  }
  return 0;
}