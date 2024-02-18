#include <bits/stdc++.h>
#define int long long
#define N 300005
using namespace std;

int d[N], n;
int lowbit(int x) {return x & -x;}
void add(int x) {
  for (int i = x; i <= n; i += lowbit(i)) {
    d[i]++;
  }
}
int get(int x) {
  int ans = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) {
    ans += d[i];
  }
  return ans;
}

struct Node {
  int v, idx;
  bool operator < (const Node &b) const {
    return v + idx - get(idx - 1) < b.v + b.idx - get(b.idx - 1);
  }
};

void solve() {
  cin >> n;
  vector<int> a(n + 1);
  vector<pair<int, int>> b(n + 2);
  // priority_queue<Node> q;
  // memset(d, 0, sizeof(d));
  for (int i = 1; i <= n; i++) {
    cin >> a[i], b[i] = {a[i], i};
  }
  stable_sort(b.begin() + 1, b.end(), [&](const pair<int, int> &x, const pair<int, int> &y) {
    return x.first + x.second > y.first + y.second;
  });
  int cnt = 0, cnt2 = 0;
  set<int, greater<int>> s;
  for (int i = 1; i <= n; i++) {
    // if (b[i].first + b[i].second == b[i - 1].first + b[i - 1].second) {
    //   cnt++;
    // } else {
    //   cnt = 0;
    // }
    s.insert(b[i].first + b[i].second - cnt);
    if (b[i + 1].first + b[i + 1].second == b[i].first + b[i].second) {
      cnt++;
    } else {
      // cnt = min(cnt, );
    }
  }
  for (auto i : s) {
    cout << i << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}