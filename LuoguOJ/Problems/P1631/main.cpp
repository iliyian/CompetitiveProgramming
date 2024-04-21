// 越界行为要不得

#include <bits/stdc++.h>
using namespace std;

int a[100001], b[100001], to[100001];

struct Node {
  int v, from;
  bool operator < (const Node &b) const {
    if (v == b.v) return from > b.from;
    return v > b.v;
  }
};
vector<int> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> a[i];
  priority_queue<Node> pq;
  for (int i = 0; i < N; i++) {
    cin >> b[i];
    pq.push({b[i] + a[0], i});
  }
  for (int i = 0; i < N; i++) {
    auto t = pq.top(); pq.pop();
    cout << t.v << ' ';
    if (to[t.from] < N - 1)
      pq.push({a[++to[t.from]] + b[t.from], t.from});
  }
  return 0;
}