#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Node {
  int v, d, val;
};

bitset<5> visv;
bitset<100005> visd;
int ans = -inf;
vector<Node> v;

void dfs2(int cur, int sum) {
  ans = max(ans, sum);
  int t = 0;
  for (int i = cur; i < v.size(); i++) {
    if (t > 3) break; // wtf??
    if (!visv[v[i].v] && !visd[v[i].d]) {
      visv[v[i].v] = true;
      visd[v[i].d] = true;
      t++;
      dfs2(cur + 1, sum + v[i].val);
      visv[v[i].v] = false;
      visd[v[i].d] = false;
    }
  }
}

void dfs(int curt, int sum) {
  if (curt == 3) {
    ans = max(ans, sum);
    return;
  }
  // auto cur = Node{0, -1, -inf};
  // for (auto &p : v) {
  //   if (p.val > cur.val && !visv[p.v] && !visd[p.d])
  //     cur = p;
  // }
  for (auto &p : v) {
    if (!visv[p.v] && !visd[p.d]) {
      visv[p.v] = true;
      visd[p.d] = true;
      dfs(curt + 1, sum + p.val);
      visv[p.v] = false;
      visd[p.d] = false;
    }
  }
}

void solve() {
  int n;
  cin >> n;

  v.clear();
  visv.reset();
  visd.reset();
  ans = -inf;

  vector<pair<int, int>> a[3];
  for (int t = 0; t < 3; t++) {
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      v.push_back({t, i, x});
    }
    // sort(a[t].begin(), a[t].end());
  }
  sort(v.begin(), v.end(), [&](const Node &a, const Node &b) {
    return a.val > b.val;
  });
  dfs2(0, 0);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}