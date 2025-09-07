#include <bits/stdc++.h>
#define int long long

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v, int len) {
        info[p].apply(v, len);
        tag[p].apply(v, len);
    }
    void push(int p, int len) {
        apply(2 * p, tag[p], len / 2);
        apply(2 * p + 1, tag[p], len - len / 2);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p, r - l);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p, r - l);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v, r - l);
            return;
        }
        int m = (l + r) / 2;
        push(p, r - l);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};
 
struct Tag {
  int val = 0;
  void apply(const Tag &t, int len) & {
    val += t.val;
  }
};
 
struct Info {
  int sum = 0;
  void apply(const Tag &t, int len) & {
    sum += t.val * len;
  }
};
 
Info operator+(const Info &a, const Info &b) {
  Info c;
  c.sum = a.sum + b.sum;
  return c;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> primes, minp(n + 1), maxp(n + 1);
  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (i * p > n) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
  std::vector<std::vector<int>> fac(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      fac[j].push_back(i);
    }
  }
  std::vector<std::vector<int>> g(n + 1);
  std::set<std::pair<int, int>> s;
  std::vector<std::vector<int>> vp(n + 1);
  HLD hld(n + 1);
  for (int i = 2; i <= n; i++) {
    int x = i;
    while (x > 1) {
      vp[i].push_back(minp[x]);
      x /= minp[x];
    }
  }
  for (int i = 2; i <= n; i++) {
    maxp[i] = vp[i].front();
    int y = i / maxp[i];
    if (!s.count(std::minmax(y, i))) {
      s.insert(std::minmax(y, i));
      hld.addEdge(y, i);
    }
  }
  // std::cout << '\n';
  hld.work(1);
  for (int i = 1; i <= n; i++) {
    std::cerr << i << '\n';
    for (int v : hld.adj[i]) {
      std::cerr << v << ' ';
    }
    std::cerr << '\n';
  }
  std::vector<int> val(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> val[i];
  }
  std::vector<Info> info(n + 1);
  for (int i = 1; i <= n; i++) {
    // std::cerr << i << ' ' << hld.seq[i - 1] << ' ' << hld.in[i] + 1 << '\n';
    info[i] = Info{val[hld.seq[i - 1]]};
  }
  LazySegmentTree<Info, Tag> seg(info);

  while (m--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, k;
      std::cin >> x >> k;
      seg.rangeApply(hld.in[x] + 1, hld.out[x] + 1, Tag{k});
    } else if (op == 2) {
      int x, k;
      std::cin >> x >> k;
      for (int y : fac[x]) {
        seg.rangeApply(hld.in[y] + 1, hld.in[y] + 2, Tag{k});
      }
    } else if (op == 3) {
      int x;
      std::cin >> x;
      int ans = 0;
//       while (x > 1) {
//         int y = minp[x];
//         while (x % y == 0) x /= y;
// 
//       }
      std::cout << seg.rangeQuery(hld.in[x] + 1, hld.out[x] + 1).sum << '\n';
    } else {
      int x;
      std::cin >> x;
      int ans = 0;
      for (int y : fac[x]) {
        ans += seg.rangeQuery(hld.in[y] + 1, hld.in[y] + 2).sum;
      }
      std::cout << ans << '\n';
    }
    for (int i = 1; i <= n; i++) {
      std::cerr << seg.rangeQuery(hld.in[i] + 1, hld.in[i] + 2).sum << ' ';
    }
    std::cerr << '\n'; 
  }
   

  return 0;
}