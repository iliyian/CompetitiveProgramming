#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

int n, m;

struct Splay {
  int pa[N], ch[N][2], cnt[N], val[N], sz[N], rv[N];
  int rt, tot;
  void maintain(int x)
  { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x]; }
  int get(int x)
  { return x == ch[pa[x]][1]; }

  void rotate(int x) {
    int y = pa[x], z = pa[pa[x]], chk = get(x);
    ch[y][chk] = ch[x][chk ^ 1];
    if (ch[x][chk ^ 1]) pa[ch[x][chk ^ 1]] = y; // 0无父
    ch[x][chk ^ 1] = y;
    pa[y] = x;
    pa[x] = z;
    if (z) ch[z][y == ch[z][1]] = x;
    maintain(y);
    maintain(x);
  }

  void splay(int x, int goal = 0) {
    if (goal == 0) rt = x;
    while (pa[x] != goal) {
      int y = pa[x], z = pa[pa[x]];
      if (z != goal) {
        rotate(get(x) == get(y) ? x : y);
      }
      rotate(x);
    }
  }

  void insert(int x) {
    if (!rt) {
      val[++tot] = x;
      cnt[tot]++;
      rt = tot;
      maintain(rt);
      return;
    }
    int cur = rt, p = 0;
    while (true) {
      if (val[cur] == x) {
        cnt[cur]++;
        maintain(cur);
        maintain(p);
        splay(cur);
        break;
      }
      p = cur;
      cur = ch[cur][val[cur] < x];
      if (!cur) {
        val[++tot] = x;
        cnt[tot]++;
        pa[tot] = p;
        ch[p][val[p] < x] = tot;
        maintain(tot);
        maintain(p);
        splay(tot);
        break;
      }
    }
  }

  int kth(int k) {
    int cur = rt;
    while (true) {
      pushdown(cur);
      if (ch[cur][0] && k <= sz[ch[cur][0]]) {
        cur = ch[cur][0];
      } else {
        k -= cnt[cur] + sz[ch[cur][0]];
        if (k <= 0) {
          splay(cur);
          return val[cur];
        }
        cur = ch[cur][1];
      }
    }
  }

  void tagrev(int x) {
    swap(ch[x][0], ch[x][1]);
    rv[x] ^= 1;
  }

  void pushdown(int x) {
    if (rv[x]) {
      tagrev(ch[x][0]);
      tagrev(ch[x][1]);
      rv[x] = 0;
    }
  }

  void reverse(int l, int r) {
    int s = kth(l - 1), t = kth(r + 1);
    splay(s), splay(t, s);
    tagrev(ch[ch[s][1]][0]);
  }

  void print(int x) {
    if (!x) return;
    pushdown(x);
    print(ch[x][0]);
    if (val[x] >= 1 && val[x] <= n) cout << val[x] << ' ';
    print(ch[x][1]);
  }
} splay; 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  cin >> n >> m;
  for (int i = 0; i <= n + 1; i++) {
    splay.insert(i);
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    splay.reverse(l, r);
  }
  splay.print(splay.rt);

  return 0;
}