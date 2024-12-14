#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 2e5 + 5;

int n, a[N];
vector<int> G[N];
bool del[N];
unordered_map<int, int> cnt, tcnt;
unordered_set<int> st, tst;
int wc, tot;
int sz[N];
long long ans[N];
void dfs_sz(int u, int fa) {
  sz[u] = 0;
  if (del[u])
    return;
  sz[u] = 1;
  for (auto &j : G[u]) {
    if (j != fa) {
      dfs_sz(j, u);
      sz[u] += sz[j];
    }
  }
}

void dfs_wc(int u, int fa) {
  if (del[u])
    return;
  int maxn = tot - sz[u];
  for (auto &j : G[u]) {
    if (j != fa) {
      dfs_wc(j, u);
      maxn = max(maxn, sz[j]);
    }
  }
  if (maxn <= tot / 2)
    wc = u;
}

int dis[N];

void dfs_dis(int u, int d, int fa) {
  if (del[u])
    return;
  dis[u] = gcd(d, a[u]);
  ans[dis[u]]++;
  cnt[dis[u]]++;
  tcnt[dis[u]]++;
  tst.insert(dis[u]);
  st.insert(dis[u]);
  for (auto &j : G[u]) {
    if (j != fa)
      dfs_dis(j, dis[u], u);
  }
}

int toto = 0;

void calc(int u) {
  if (del[u])
    return;
  // std::cout << u << '\n';
  cnt.clear();
  st.clear();
  wc = 0;
  tot = 0;
  dfs_sz(u, 0);
  tot = sz[u];
  dfs_wc(u, 0);
  u = wc;
  del[u] = 1;
  tcnt.clear();
  tst.clear();
  toto += sz[u];
  for (auto j : G[u]) {
    cnt.clear();
    st.clear();
    dfs_dis(j, a[u], u);
    for (auto &k1 : st) {
      for (auto &k2 : st) {
        if (k2 < k1)
          continue;
        if (k1 == k2) {
          ans[k1] -= (1LL * cnt[k1] * (cnt[k1] - 1LL) / 2LL);
        } else {
          ans[gcd(k1, k2)] -= (1LL * cnt[k1] * cnt[k2]);
        }
      }
    }
  }
  for (auto &k1 : tst) {
    for (auto &k2 : tst) {
      if (k2 < k1)
        continue;
      if (k1 == k2) {
        ans[k1] += (1LL * tcnt[k1] * (tcnt[k1] - 1LL) / 2);
      } else {
        ans[gcd(k1, k2)] += (1LL * tcnt[k1] * tcnt[k2]);
      }
    }
  }
  // cout << "\n\n";
  for (auto j : G[u]) {
    calc(j);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans[a[i]]++;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  calc(1);
  for (int i = 1; i <= 200000; i++) {
    if (ans[i]) {
      // printf("%d %lld\n", i, ans[i]);
    }
  }
  std::cout << toto << '\n';
  return 0;
}