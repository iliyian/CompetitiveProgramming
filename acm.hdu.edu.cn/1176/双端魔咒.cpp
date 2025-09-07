// date: 2025-08-04 10:29:10
// tag: 这题补的太痛苦和没价值了。什么抽象的广义后缀自动机上二维数点

#include <bits/stdc++.h>
#include <climits>
#define int long long

using i64 = long long;

struct SAM { // also gsam
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET_SIZE> next;
        Node() : len{}, link{}, next{} {}
    };
    std::vector<Node> t;
    SAM() {
        init();
    }
    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int extend(int p, int c) {
        if (t[p].next[c]) {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1) {
                return q;
            }
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next[c]) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        return cur;
    }
    // int extend(int p, char c, char offset = 'a') {
    //     return extend(p, c - offset);
    // }
    
    int next(int p, int x) {
        return t[p].next[x];
    }
    
    // int next(int p, char c, char offset = 'a') {
    //     return next(p, c - 'a');
    // }
    
    int link(int p) {
        return t[p].link;
    }
    
    int len(int p) {
        return t[p].len;
    }
    
    int size() {
        return t.size();
    }
};

void solve() {
  int l, r;
  std::cin >> l >> r;
  auto work = [&](std::vector<std::string> &s, std::string &str) {
    SAM sam;
    int len = 0;
    for (auto &x : s) {
      len += x.size();
    }
    std::vector<int> f(len * 2 + 1, LLONG_MAX / 3);
    for (auto &x : s) {
      int p = 1;
      for (char c : x) {
        p = sam.extend(p, c - 'a');
      }
      f[p] = std::min<int>(f[p], x.size());
    }
    std::vector<int> q(sam.size());
    std::iota(q.begin(), q.end(), 0);
    std::ranges::sort(q, [&](auto x, auto y) {
      return sam.len(x) < sam.len(y);
    });
    for (int u : q) {
      f[u] = std::min(f[u], f[sam.link(u)]);
      // if (sam.link(u)) {
      //   f[sam.link(u)] = std::min(f[sam.link(u)], f[u]);
      // }
    }

    int n = str.size();
    int p = 1, nowlen = 0;
    std::vector<int> F(n, -1);
    for (int i = 0; i < str.size(); i++) {
      while (p > 1 && !sam.next(p, str[i] - 'a')) { // 应该是O(n)的
        p = sam.link(p);
        nowlen = sam.len(p);
      }
      if (sam.next(p, str[i] - 'a')) {
        nowlen++;
        p = sam.next(p, str[i] - 'a');
        if (i - f[p] + 1 >= 0 && nowlen >= f[p]) {
          F[i] = i - f[p] + 1;
        }
      } else {
        assert(p == 1);
        // p = 1;
        nowlen = 0;
      }
    }
    return F;
  };
  std::vector<std::string> ls(l), rs(r);
  for (int i = 0; i < l; i++) {
    std::cin >> ls[i];
    std::ranges::reverse(ls[i]);
  }
  for (int i = 0; i < r; i++) {
    std::cin >> rs[i];
  }
  std::string str;
  std::cin >> str;
  auto R = work(rs, str);
  std::ranges::reverse(str);
  auto L = work(ls, str);
  std::ranges::reverse(L);
  int n = str.size();

  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) -> void {
    x++;
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) -> int {
    x++;
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };

  for (int i = 0; i < n; i++) {
    if (L[i] != -1) {
      L[i] = n - 1 - L[i];
    }
  }

  // for (int i = 0; i < n; i++) {
  //   std::cerr << (L[i] == LLONG_MAX / 3 ? -1 : L[i]) << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 0; i < n; i++) {
  //   std::cerr << (R[i] == LLONG_MAX / 3 ? -1 : R[i]) << ' ';
  // }
  // std::cerr << '\n';

  std::vector<std::vector<int>> rl(n);
  for (int i = 0; i < n; i++) {
    if (L[i] != -1) {
      rl[L[i]].push_back(i);
    }
  }
  int ans = 0;
  for (int j = 0; j < n; j++) {
    for (int i : rl[j]) {
      add(i, 1);
    }
    if (R[j] != -1) {
      ans += query(R[j]);
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}