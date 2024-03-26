// date: 2024-03-26 19:21:50
// tag: 哈希，堆优化的bfs

#include <bits/stdc++.h>
#define int long long
#define mod1 998244353
#define mod2 1000000007
#define N 200005
using namespace std;

struct Node {
  int sum;
  array<int, 11> t;
  bool operator < (const Node &b) const {
    return sum < b.sum;
  }
};

vector<vector<int>> a;
set<int> hashes, vis;
int n, m;
priority_queue<Node> q;

int qpow(int a, int b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}

int hashp(const array<int, 11> &s, int p) {
  int h = 0;
  for (int i = 1; i <= n; i++) {
    h = (qpow(N, i - 1, p) * s[i] % p + h) % p;
  }
  return h;
}

int hash0(const array<int, 11> &s) {
  return hashp(s, mod1) * mod2 + hashp(s, mod2);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    a[i].resize(c + 1);
    for (int j = 1; j <= c; j++) {
      cin >> a[i][j];
    }
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    array<int, 11> s;
    for (int j = 1; j <= n; j++) {
      cin >> s[j];
    }
    hashes.insert(hash0(s));
    hashes.insert(hash0(s));
  }

  array<int, 11> s;
  int sm = 0;
  for (int i = 1; i <= n; i++) {
    s[i] = a[i].size() - 1;
    sm += a[i][s[i]];
  }
  q.push({sm, s});
  while (!q.empty()) {
    auto [sm, s] = q.top(); q.pop();
    int h = hash0(s);
    if (vis.count(h)) {
      continue;
    }
    vis.insert(h);
    if (!hashes.count(hash0(s))) {
      for (int i = 1; i <= n; i++) {
        cout << s[i] << ' ';
      }
      return 0;
    }
    for (int i = 1; i <= n; i++) {
      if (s[i] > 1) {
        s[i]--;
        sm = sm - a[i][s[i] + 1] + a[i][s[i]];
        q.push({sm, s});
        sm = sm - a[i][s[i]] + a[i][s[i] + 1];
        s[i]++;
      }
    }
  }
  cout << -1 << '\n';

  return 0;
}