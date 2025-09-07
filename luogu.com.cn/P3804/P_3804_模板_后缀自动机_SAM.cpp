// date: 2025-08-02 23:24:56
// tag: sam板子

#include <bits/stdc++.h>
// #define int long long

using i64 = long long;

struct SAM {
    static constexpr int32_t ALPHABET_SIZE = 26;
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
    int extend(int p, char c, char offset = 'a') {
        return extend(p, c - offset);
    }
    
    int next(int p, int x) {
        return t[p].next[x];
    }
    
    int next(signed p, char c, char offset = 'a') {
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
};

void solve() {
  std::string str;
  std::cin >> str;
  SAM sam;
  int last = 1, n = str.size();
  std::vector<int> cnt(n * 2 + 2);
  for (int i = 0; i < str.size(); i++) {
    last = sam.extend(last, str[i]);
    cnt[last] = 1;
  }
  std::vector<int> p(sam.size());
  std::iota(p.begin(), p.end(), 0);
  std::ranges::sort(p, [&](auto x, auto y) {
    return sam.len(x) > sam.len(y);
  });
  i64 ans = 0;
  for (int i : p) {
    cnt[sam.link(i)] += cnt[i];
  }
  for (int i : p) {
    if (cnt[i] > 1) {
      // std::cout << i << ' ' << cnt[i] << ' ' << sam.len(i) << '\n';
      ans = std::max(ans, i64(cnt[i]) * sam.len(i));
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