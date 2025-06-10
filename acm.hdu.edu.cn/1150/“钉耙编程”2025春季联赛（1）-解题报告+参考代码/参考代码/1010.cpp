#include <bits/stdc++.h>

typedef long long int64;

const int N = 100000;

int n, cq, a[N + 9];
std::vector<int> e[N + 9];

void Read() {
  std::cin >> n >> cq;
  for (int i = 1; i <= n; ++i)
    e[i].clear();
  for (int i = 1; i <= n; ++i)
    std::cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    int x, y;
    std::cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
}

int vis[N + 9], tag[N + 9];
std::vector<int> sta, cyc;

bool DFSCycle(int x, int fa) {
  vis[x] = 1;
  sta.push_back(x);
  for (int y : e[x]) {
    if (y == fa)
      continue;
    if (!vis[y]) {
      if (DFSCycle(y, x))
        return 1;
      continue;
    }
    for (;;) {
      int t = sta.back();
      sta.pop_back();
      cyc.push_back(t);
      tag[t] = 1;
      if (t == y)
        return 1;
    }
  }
  vis[x] = 0;
  sta.pop_back();
  return 0;
}

int bel[N + 9];

void DFSBel(int x, int fa, int id) {
  bel[x] = id;
  for (int y : e[x]) {
    if (y == fa)
      continue;
    if (tag[y])
      continue;
    DFSBel(y, x, id);
  }
}

void FindCycle() {
  for (int i = 1; i <= n; ++i)
    vis[i] = tag[i] = 0;
  sta.clear();
  cyc.clear();
  // std::cerr<<" ll\n";
  DFSCycle(1, 0);
  // std::cerr<<" ll\n";
  for (int i = 1; i <= n; ++i)
    bel[i] = -1;
  for (int i = 0; i < (int)cyc.size(); ++i)
    DFSBel(cyc[i], 0, i);
  // std::cerr<<" ll\n";
  int x = cyc.front();
  int y = cyc.back();
  e[x].erase(std::find(e[x].begin(), e[x].end(), y));
  e[y].erase(std::find(e[y].begin(), e[y].end(), x));
  // std::cerr<<" ll\n";
}

int fa[N + 9], son[N + 9], siz[N + 9], dep[N + 9], top[N + 9];
int dfs[N + 9], ord[N + 9], co;

void DFSHDL0(int x, int fat) {
  fa[x] = fat;
  dep[x] = dep[fat] + 1;
  siz[x] = 1;
  son[x] = 0;
  for (int y : e[x]) {
    if (y == fat)
      continue;
    DFSHDL0(y, x);
    siz[x] += siz[y];
    if (siz[y] > siz[son[x]])
      son[x] = y;
  }
}

void DFSHDL1(int x, int t) {
  top[x] = t;
  ord[++co] = x;
  dfs[x] = co;
  if (son[x])
    DFSHDL1(son[x], t);
  for (int y : e[x])
    if (y != fa[x] && y != son[x])
      DFSHDL1(y, y);
}

struct tree {
  int64 sum, pre, suf, max;
  tree() : sum(0), pre(0), suf(0), max(0) {}
  tree(int64 v) : sum(v) { pre = suf = max = std::max(v, 0LL); }
  tree(int64 _sum, int64 _pre, int64 _suf, int64 _max)
      : sum(_sum), pre(_pre), suf(_suf), max(_max) {}
  tree swap() const { return tree(sum, suf, pre, max); }
} tr[N * 4 + 9];

tree operator+(const tree &a, const tree &b) {
  return tree(a.sum + b.sum, std::max(a.pre, a.sum + b.pre),
              std::max(b.suf, b.sum + a.suf),
              std::max({a.max, b.max, a.suf + b.pre}));
}

void Build(int l, int r, int k) {
  if (l == r)
    return (void)(tr[k] = tree(a[ord[l]]));
  int mid = (l + r) >> 1;
  Build(l, mid, k << 1);
  Build(mid + 1, r, k << 1 | 1);
  tr[k] = tr[k << 1] + tr[k << 1 | 1];
}

void Change(int p, int v, int l, int r, int k) {
  if (l == r)
    return (void)(tr[k] = tree(v));
  int mid = (l + r) >> 1;
  p <= mid ? Change(p, v, l, mid, k << 1)
           : Change(p, v, mid + 1, r, k << 1 | 1);
  tr[k] = tr[k << 1] + tr[k << 1 | 1];
}

tree Query(int ql, int qr, int l, int r, int k) {
  if (ql <= l && qr >= r)
    return tr[k];
  int mid = (l + r) >> 1;
  if (qr <= mid)
    return Query(ql, qr, l, mid, k << 1);
  if (ql > mid)
    return Query(ql, qr, mid + 1, r, k << 1 | 1);
  return Query(ql, qr, l, mid, k << 1) + Query(ql, qr, mid + 1, r, k << 1 | 1);
}

void Change(int x, int v) { Change(dfs[x], v, 1, n, 1); }

int LCA(int x, int y) {
  for (; top[x] != top[y]; x = fa[top[x]])
    if (dep[top[x]] < dep[top[y]])
      std::swap(x, y);
  return dep[x] < dep[y] ? x : y;
}

tree Query(int x, int y) {
  int z = LCA(x, y);
  bool b = 1;
  tree left;
  for (; top[x] != top[z]; x = fa[top[x]]) {
    tree t = Query(dfs[top[x]], dfs[x], 1, n, 1).swap();
    left = b ? t : left + t;
    b = 0;
  }
  {
    tree t = Query(dfs[z], dfs[x], 1, n, 1).swap();
    left = b ? t : left + t;
  }
  if (y == z)
    return left;
  b = 1;
  tree right;
  for (; top[y] != top[z]; y = fa[top[y]]) {
    tree t = Query(dfs[top[y]], dfs[y], 1, n, 1).swap();
    right = b ? t : right + t;
    b = 0;
  }
  if (y != z) {
    tree t = Query(dfs[z] + 1, dfs[y], 1, n, 1).swap();
    right = b ? t : right + t;
  }
  return left + right.swap();
}

void HDL() {
  DFSHDL0(1, 0);
  co = 0;
  DFSHDL1(1, 1);
  Build(1, n, 1);
}

void Inter() {
  int64 xr = 0;
  for (; cq--;) {
    std::string o;
    int x, y;
    std::cin >> o >> x >> y;
    if (o == "C")
      Change(x, y);
    else {
      int64 ans = Query(x, y).max;
      if (bel[x] != bel[y]) {
        if (bel[x] > bel[y])
          std::swap(x, y);
        ans = std::max(ans, (Query(x, cyc.front()) + Query(cyc.back(), y)).max);
      }
      // std::cerr<<ans<<'\n';
      xr ^= ans;
    }
  }
  std::cout << xr << '\n';
}

void work() {
  Read();
  // std::cerr<<"kk\n";
  FindCycle();
  // std::cerr<<"kk\n";
  HDL();
  // std::cerr<<"kk\n";
  Inter();
  // std::cerr<<"kk\n";
}

int main() {
  int size(256 << 20); // 256M
  __asm__("movq %0, %%rsp\n" ::"r"((char *)malloc(size) + size));
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T = 1;
  std::cin >> T;
  for (; T--;)
    work();
  exit(0);
}