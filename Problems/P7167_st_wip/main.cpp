#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int D[200001], C[200001], nxt[200001][20], sum[200001][20];

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> D[i] >> C[i];
  }
  D[N + 1] = C[N + 1] = inf;
  memset(sum, 0, sizeof(sum));
  stack<int> st;
  st.push(N + 1);
  for (int i = N; i >= 1; i--) {
    while (!st.empty() && D[st.top()] <= D[i])
      st.pop();
    nxt[i][0] = st.top();
    sum[i][0] = C[i];
    st.push(i);
  }

  for (int j = 1; (1 << j) <= N; j++)
    for (int i = 1; i + (1 << j) <= N; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      sum[i][j] = sum[i][j - 1] + sum[nxt[i][j - 1]][j - 1]; // ?
    }

  for (int i = 0; i < Q; i++) {
    int R, V;
    cin >> R >> V;
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