#include <bits/stdc++.h>
using namespace std;

struct Node {
  string id;
  int from, score, fromrank;
  bool operator < (const Node &b) const {
    if (score == b.score) return id < b.id;
    return score > b.score;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("J.in", "r", stdin);
  int n;
  cin >> n;
  vector<Node> nodes;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    vector<Node> cur;
    for (int j = 0; j < k; j++) {
      string id;
      int score;
      cin >> id >> score;
      cur.push_back({id, i, score});
    }
    sort(cur.begin(), cur.end());
    for (int j = 0; j < cur.size(); j++) {
      cur[j].fromrank = lower_bound(cur.begin(), cur.end(), Node{"0000000", -1, cur[j].score}) - cur.begin() + 1;
      nodes.push_back(cur[j]);
    }
  }
  sort(nodes.begin(), nodes.end());
  cout << nodes.size() << '\n';
  for (int i = 0; i < nodes.size(); i++) {
    cout << nodes[i].id << ' '
    << 1 + lower_bound(nodes.begin(), nodes.end(), Node{"00000000", -1, nodes[i].score}) - nodes.begin()
    << ' ' << nodes[i].from << ' ' << nodes[i].fromrank << '\n';
  }
}