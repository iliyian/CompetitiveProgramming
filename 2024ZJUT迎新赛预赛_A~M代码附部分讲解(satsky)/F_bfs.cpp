// 妙啊，从叶子开始类似拓扑排序地删点
// 关键在于只砍去真的没有人需要的点
// 关键在于动态维护叶子
// 动态维护叶子并砍去，表啊

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
          cc[v]++; // 锟斤拷锟斤拷
    for (int i = 1, x; i <= k; i++)
      cin >> x, lit[x] = 1;
    queue<int> Q;
    for (int i = 1; i <= n; i++)
      if (cc[i] == 1)
        Q.push(i);
    while (!Q.empty()) // 锟斤拷锟斤拷删去锟斤拷锟斤拷(锟斤拷锟斤拷锟斤拷)=1锟侥碉拷(叶锟斤拷)
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