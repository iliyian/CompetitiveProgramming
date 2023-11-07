// wa#0: pa数组开小了

#include <bits/stdc++.h>
using namespace std;

vector<string> v;

struct Edge {
  int v, ord;
  string str;
  bool operator < (const Edge &b) const {
    return str < b.str;
  }
};
vector<vector<Edge>> g;

int in[27], out[27], pa[27], eu_begi, eu_end, n;
bitset<27> vis;
bitset<1001> visw;

int find(int x) {
  return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void fail() {
  cout << "***";
  exit(0);
}

void checkscnt() {
  for (int i = 1; i <= n; i++) {
    int fro = v[i].front() - 'a' + 1, bac = v[i].back() - 'a' + 1;
    g[fro].push_back({bac, i, v[i]});

    in[fro]++, out[bac]++;
    vis[fro] = vis[bac] = true;

    if (fro != bac) {
      int pfro = find(fro), pbac = find(bac);
      if (pfro != pbac)
        pa[pfro] = pbac;
    }
  }

  int scnt = 0;
  for (int i = 1; i <= 26; i++) {
    if (vis[i] && find(i) == i) scnt++;
  }
  if (scnt != 1) fail();
}

void checkdeg() {
  for (int i = 1; i <= 26; i++) {
    if (!vis[i]) continue;
    if (in[i] - out[i] == 1) {
      if (eu_begi)
        fail();
      eu_begi = i;
    }
    else if (out[i] - in[i] == 1) {
      if (eu_end)
        fail();
      eu_end = i;
    }
    else if (in[i] != out[i])
      fail();
  }
}

vector<string> ans;

void dfs(int cur) {
  if (ans.size() == n) {
    for (int i = 0; i < ans.size(); i++) {
      if (i) cout << '.';
      cout << ans[i];
    }
    exit(0);
  }
  for (auto &ed : g[cur]) {
    int ord = ed.ord, v = ed.v;
    if (visw[ord]) continue;

    visw[ord] = true;
    ans.push_back(ed.str);
    dfs(v);
    ans.pop_back();
    visw[ord] = false;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n;
  g.resize(27);
  v.resize(n + 1);
  for (int i = 1; i <= 26; i++)
    pa[i] = i;
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  sort(v.begin() + 1, v.end());

  eu_begi = eu_end = 0;
  checkscnt();
  checkdeg();

  if (!eu_begi ^ !eu_end)
    fail();
  if (!eu_begi & !eu_end)
    eu_begi = v[1].front() - 'a' + 1;

  dfs(eu_begi);

  cout << "***";
  return 0;
}