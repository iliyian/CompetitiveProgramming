#include <bits/stdc++.h>
#define N 200005
using namespace std;

int dfn[N], low[N], ins[N], s[N], sccno[N], siz[N];
int tp = 0, scc_cnt = 0, dfncnt = 0;

int n, m;
vector<vector<int>> g;

void tarjan1(int u) {
  dfn[u] = low[u] = ++dfncnt;
  ins[u] = true, s[++tp] = u;
  for (auto v : g[u]) {
    if (!dfn[v]) {
      tarjan1(v);
      low[u] = min(low[u], dfn[u]);
    } else if (ins[v]) {
      // greedy
      low[u] = min(low[u], low[v]);
    }
  }
  if (low[u] == dfn[u]) {
    ++scc_cnt;

    do {
      int x = s[tp];
      siz[scc_cnt]++;
      sccno[x] = scc_cnt;
      ins[x] = false;
    } while (s[tp--] != u);

    // or

    while (s[tp] != u) {
      siz[s[tp]]++;
      sccno[s[tp]] = scc_cnt;
      ins[s[tp]] = false;
      tp--;
    }
    siz[s[tp]]++;
    sccno[s[tp]] = scc_cnt;
    ins[s[tp]] = false;
    tp--;

  }
}

// OR
// I hope it works, hope no typo;

stack<int> st;
void tarjan2(int u) {
  dfn[u] = low[u] = ++dfncnt;
  st.push(u);
  for (auto v : g[u]) {
    if (!dfn[v]) {
      tarjan2(v);
      // greedy
      low[u] = min(low[u], dfn[v]);
    } else if (!sccno[v]) { // ?
      low[u] = min(low[u], low[v]);
    }
  }
  if (dfn[u] == low[u]) {
    scc_cnt++;
    while (true) {
      int x = st.top(); st.pop();
      siz[x]++;
      sccno[x] = scc_cnt;
      if (x == u) break;
    }
  }
}
