#include <bits/stdc++.h>
// #define int long long

using i64 = long long;

struct SAM {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len;
        int link;
        int siz = 1;
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
    int extend(int32_t p, int c) {
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
    int extend(int p, char c, char offset = 'a') {
        return extend(p, c - offset);
    }
    
    int next(int32_t p, int32_t x) {
        return t[p].next[x];
    }
    
    int next(int32_t p, char c, char offset = 'a') {
        return next(p, c - 'a');
    }
    
    int link(int p) {
        return t[p].link;
    }
    
    int len(int p) {
        return t[p].len;
    }
    
    int size() {
        return t.size();
    }
    
    int siz(int p) {
      return t[p].siz;
    }
};

void solve() {
  std::string str;
  std::cin >> str;
  i64 t, k;
  std::cin >> t >> k;
  SAM sam;
  int p = 1;
  std::vector<i64> v, f(str.size() * 2), siz(str.size() * 2);
  for (int i = 0; i < str.size(); i++) {
    p = sam.extend(p, str[i]);
    siz[p] = 1; 
    v.push_back(p);
  }
  int n = sam.size();
  std::vector<int> q(n);
  std::iota(q.begin(), q.end(), 0);
  std::ranges::sort(q, [&](auto x, auto y) {
    return sam.len(x) > sam.len(y);
  });
  if (t == 1) {
    for (int i : q) {
      if (sam.link(i)) {
        siz[sam.link(i)] += siz[i];
      }
    }
  } else {
    std::ranges::fill(siz, 1);
  }
  siz[0] = f[0] = siz[1] = f[1] = 0;
  for (int i : q) {
    f[i] = siz[i];
    for (int j = 0; j < 26; j++) {
      int v = sam.next(i, j);
      f[i] += f[v];
    }
  }
  int u = 1;
  std::string ans;
  if (k > f[1]) {
    std::cout << -1 << '\n';
    return;
  }
  while (k > 0) {
    for (int i = 0; i < 26; i++) {
      int v = sam.next(u, i);
      if (v > 1) {
        if (k > f[v]) {
          k -= f[v];
        } else {
          k -= siz[v];
          ans += char('a' + i);
          u = v;
          break;
        }
      }
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}