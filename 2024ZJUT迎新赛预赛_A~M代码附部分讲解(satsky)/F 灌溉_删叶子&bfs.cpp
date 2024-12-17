// Ãî°¡£¬´ÓÒ¶×Ó¿ªÊ¼ÀàËÆÍØÆËÅÅĞòµØÉ¾µã

#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
struct S {
  int n, k, res = 0;
  vector<vector<int>> es;
  vector<int> lit, u, v, cc;
  void ini() {
    cin >> n >> k;
    cc.resize(n + 1, 0);
    lit = u = v = cc;
    es.resize(n + 1);
    for (int i = 1, u, v; i < n; i++)
      cin >> u >> v, es[u].push_back(v), es[v].push_back(u), cc[u]++,
          cc[v]++; // ï¿½ï¿½ï¿½ï¿½
    for (int i = 1, x; i <= k; i++)
      cin >> x, lit[x] = 1;
    queue<int> Q;
    for (int i = 1; i <= n; i++)
      if (cc[i] == 1)
        Q.push(i);
    while (!Q.empty()) // ï¿½ï¿½ï¿½ï¿½É¾È¥ï¿½ï¿½ï¿½ï¿½(ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½)=1ï¿½Äµï¿½(Ò¶ï¿½ï¿½)
    {
      auto x = Q.front();
      Q.pop();
      if (lit[x])
        continue;
      res++;
      for (auto &k : es[x])
        if ((--cc[k]) == 1)
          Q.push(k);
    }
    cout << n - res << '\n';
  }
  void solve() {}
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  S SS;
  SS.ini();
  SS.solve();
}