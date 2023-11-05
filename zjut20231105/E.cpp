#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1000001], sum[1000001];
bitset<1000001> spe;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

struct Node {
  int p, q, idx;
  bool operator < (const Node &b) const {
    if (idx == b.idx) 
      return p / q > b.p / b.q;
    return idx > b.idx;
  }
};

void solve() {
  int n;
  cin >> n;
  // int p = 1, q = 1;
  bool f = true;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  priority_queue<Node> pq;

  pq.push(Node{1, 1, -1});
  while (!pq.empty()) {
    Node node = pq.top(); pq.pop();
    int p = node.p, q = node.q, idx = node.idx;
    if (idx == n - 1) {
      int g = gcd(p, q);
      cout << p / g << ' ' << q / g << '\n';
      return;
    }
    switch (a[idx + 1]) {
      case 1:
        pq.push({p + 1, q + 1, idx + 1});
        break;
      case -1:
        if (q >= 2) {
          pq.push({p, q - 1, idx + 1});
        }
      break;
      default:
        if (q >= 2) {
          pq.push({p, q - 1, idx + 1});
        } else {
          pq.push({p + 1, q + 1, idx + 1});
        }
      break;
    }
  }
  cout << "-1\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  int T; cin >> T;
  while (T--) solve();
  return 0;
}