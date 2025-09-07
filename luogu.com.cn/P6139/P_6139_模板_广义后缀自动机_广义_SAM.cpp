#include <bits/stdc++.h>
#define int long long

using i64 = long long;

struct SAM {
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
  int n;
  std::cin >> n;
  SAM sam;
  for (int i = 1; i <= n; i++) {
    int last = 1;
    std::string str;
    std::cin >> str;
    for (char c : str) {
      last = sam.extend(last, c - 'a');
    }
  }
  int m = sam.size(), ans = 0;
  for (int i = 2; i < m; i++) {
    ans += sam.len(i) - sam.len(sam.link(i));
  }
  std::cout << ans << '\n' << m - 1 << '\n';
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

// #include <bits/stdc++.h>
// using namespace std;
// 
// const int N = 2e6 + 5;
// int n;
// struct Suffix_Automaton {
//   int O, link[N], len[N], next[N][26];
//   // link[i]: 后缀链接
//   // next[i]: 状态转移数组
//   Suffix_Automaton() { O = 1; } // 根初始化为1
//   inline int insert(int ch, int last) {
//     if (next[last][ch]) {
//       int p = last, x = next[p][ch];
//       if (len[p] + 1 == len[x])
//         return x; // 即最初的特判1
//       else {
//         int y = ++O;
//         len[y] = len[p] + 1;
//         for (int i = 0; i < 26; ++i)
//           next[y][i] = next[x][i];
//         while (p && next[p][ch] == x)
//           next[p][ch] = y, p = link[p];
//         link[y] = link[x], link[x] = y;
//         return y; // 即最初的特判2
//       }
//     }
//     int z = ++O, p = last;
//     len[z] = len[last] + 1;
//     while (p && !next[p][ch])
//       next[p][ch] = z, p = link[p];
//     if (!p)
//       link[z] = 1;
//     else {
//       int x = next[p][ch];
//       if (len[p] + 1 == len[x])
//         link[z] = x;
//       else {
//         int y = ++O;
//         len[y] = len[p] + 1;
//         for (int i = 0; i < 26; ++i)
//           next[y][i] = next[x][i];
//         while (p && next[p][ch] == x)
//           next[p][ch] = y, p = link[p];
//         link[y] = link[x], link[z] = link[x] = y;
//       }
//     }
//     return z;
//   }
// } SAM;
// 
// int main() {
// 
// }
