// date: 2024-03-14 00:40:49
// tag: CDQ分治，树状数组
// re,wa#01: 没有考虑到树状数组add的边界是值的边界即k而非vector的len

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int a, b, c;
  int cnt, res;
  bool operator != (const Node &y) const {
    return tie(a, b, c) != tie(y.a, y.b, y.c);
  }
};

bool cmpA(const Node &x, const Node &y) {
  return tie(x.a, x.b, x.c) < tie(y.a, y.b, y.c);
}

bool cmpB(const Node &x, const Node &y) {
  return tie(x.b, x.c) < tie(y.b, y.c);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> c(k + 1);
  vector<Node> nodes(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> nodes[i].a >> nodes[i].b >> nodes[i].c;
  }
  sort(nodes.begin() + 1, nodes.end() - 1, cmpA);
  vector<Node> vec = {{0, 0, 0, 0, 0}};
  int t = 0;
  for (int i = 1; i <= n; i++) {
    t++;
    if (nodes[i] != nodes[i + 1]) {
      nodes[i].cnt = t;
      vec.push_back(nodes[i]);
      t = 0;
    }
  }
  // nodes.back().cnt = t + 1;
  // vec.push_back(nodes.back());
  int len = vec.size();

  auto lowbit = [&](int x) {
    return x & -x;
  };

  auto add = [&](int x, int v) {
    for (int i = x; i <= k; i += lowbit(i)) { // [)，一般是[]的
      c[i] += v;
    }
  };

  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
      ans += c[i];
    }
    return ans;
  };

  auto CDQ = [&](auto self, int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    self(self, l, mid);
    self(self, mid + 1, r);
    sort(vec.begin() + l, vec.begin() + mid + 1, cmpB);
    sort(vec.begin() + mid + 1, vec.begin() + r + 1, cmpB);
    int i = l, j = mid + 1;
    while (j <= r) {
      while (i <= mid && vec[i].b <= vec[j].b) {
        add(vec[i].c, vec[i].cnt);
        i++;
      }
      vec[j].res += query(vec[j].c);
      j++;
    }
    for (int k = l; k < i; k++) {
      add(vec[k].c, -vec[k].cnt);
    }
  };
  for (int i = 1; i < len; i++) {
    assert(vec[i].cnt > 0);
  }

  CDQ(CDQ, 1, len - 1);
  vector<int> ans(n);
  for (int i = 1; i < len; i++) {
    ans[vec[i].res + (vec[i].cnt - 1)] += vec[i].cnt;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}