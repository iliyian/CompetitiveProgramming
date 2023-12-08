// date: 2023/12/8
// tle#01: vector<bool>效率远低于bitset<N>
// wa#02: N把10^5搞成10^4了
// tag: graph
// 顺便，codeforces上似乎版本越高的g++编译的程序越快？

#include <bits/stdc++.h>
#define N 100005
using namespace std;

// int nxt[N], in[N];
// bool a[N];
// bitset<N> vis;

void solve() {
  int n;
  cin >> n;
  vector<int> nxt(n), in(n);
  bitset<N> vis, a;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = c == '1';
  }
  for (int i = 0; i < n; i++) {
    cin >> nxt[i];
    in[--nxt[i]]++;
  }

  vector<int> ans;
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (!in[i])
      q.push(i);

  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (a[x]) {
      a[x] = !a[x], a[nxt[x]] = !a[nxt[x]];
      ans.push_back(x);
    }
    if (!--in[nxt[x]])
      q.push(nxt[x]);
  }
  
  for (int i = 0; i < n; i++)
    // one time a circle
    if (!vis[i] && a[i]) {
      int x = i, sum = 0;

      vector<int> v;
      while (!vis[x]) {
        sum += a[x];
        v.push_back(x);
        vis[x] = true;
        x = nxt[x];
      }
      // it's a ring
      v.push_back(x);
      if (sum & 1) {
        cout << -1 << '\n';
        return;
      }

      // 决定了一个，就决定了所有
      vector<int> res1;
      bitset<N> va = a;
      // copy(a.begin(), a.end(), va.begin());

      for (int j = 0; j < v.size() - 1; j++) {
        int t = v[j];
        if (j == 0 || va[t]) {
          res1.push_back(t);
          va[t] = !va[t], va[nxt[t]] = !va[nxt[t]];
        }
      }

      vector<int> res2;
      va = a;
      // copy(a.begin(), a.end(), va.begin());
      for (int j = 0; j < v.size() - 1; j++) {
        int t = v[j];
        if (j > 0 && va[t]) {
          res2.push_back(t);
          va[t] = !va[t], va[nxt[t]] = !va[nxt[t]];
        }
      }
      auto &ansv = res1.size() < res2.size() ? res1 : res2;
      for (auto j : ansv)
        ans.push_back(j);
    }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("G.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}