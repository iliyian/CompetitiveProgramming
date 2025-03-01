#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int D[200001], C[200001], nxt[200001][20], sum[200001][20], N, Q, dep[200001];
vector<vector<int>> g;

void dfs(int u, int pa) {
  nxt[u][0] = pa, sum[u][0] = C[pa];
  dep[u] = dep[pa] + 1;
  for (int i = 1; 1 << i <= dep[u]; i++) {
    nxt[u][i] = nxt[nxt[u][i - 1]][i - 1];
    sum[u][i] = sum[nxt[u][i - 1]][i - 1] + sum[u][i - 1];
    // ?
  }
  for (int v : g[u]) {
    if (v == pa) continue;
    dfs(v, u);
  }
}

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> D[i] >> C[i];
  }
  D[N + 1] = C[N + 1] = inf;
  memset(sum, 0, sizeof(sum));
  stack<int> st;
  st.push(N + 1);
  g.resize(N + 2);
  for (int i = N; i >= 1; i--) {
    while (!st.empty() && D[st.top()] <= D[i])
      st.pop();
    g[st.top()].push_back(i);
    st.push(i);
  }
  dfs(N + 1, 0);
  for (int i = 0; i < Q; i++) {
    int R, V;
    cin >> R >> V;
    if (V <= C[R]) {
      cout << R << '\n';
      continue;
    }
    V -= C[R];
    for (int i = 19; i >= 0; i--) {
      if (nxt[R][i] && V > sum[R][i]) {
        V -= sum[R][i];
        R = nxt[R][i];
      }
    }
    cout << (nxt[R][0] == N + 1 ? 0 : nxt[R][0]) << '\n';
  }
  return 0;
}