// date: 2024/02/02 14:01:13
// tag: 剪枝放在循环里面，也就是放在push之前，会快很多很多！！！！！！
//
// tle#01: 用了map，因为没想到1<<27都tmd不爆内存，内存计算原来只看实际使用的吗？？？
// wa#02: 路径重叠
// 虽然但是这种改变剪枝代码位置就大大提升速度的情况似乎挺罕见吧
// 反正以后A*要这么写了......
//
// 顺便这题开不开O2时间明明差不多
// A*应该也可以应用在类似这种情况的，h(x)是各部位之和，的题目，比如转锁等
// 只要便于计算h(x)即可，也就是题目目标明确的

#include <bits/stdc++.h>
using namespace std;

int h(int x) {
  int sum = 0;
  for (int i = 0; i < 12; i++)
    sum += (4 - ((x >> i * 2) & 3)) & 3;
  return sum;
}

struct Node {
  int u, dis, h;
  bool operator < (const Node &b) const {
    return dis + h > b.dis + b.h;
  }
};

int f[12][4];
// map<int, int> prv, button;
int prv[1 << 24], button[1 << 24];
// 这tmd竟然不爆

int src = 0;

void write(int x) {
  if (x == src) return;
  write(prv[x]);
  cout << button[x] << ' ';
}

void solve() {
  priority_queue<Node> q;
  for (int i = 0; i < 12; i++) {
    int x;
    cin >> x;
    src = src + (x - 1 << i * 2);
    for (int j = 0; j < 4; j++)
      cin >> f[i][j];
  }
  q.push({src, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, dis = node.dis;
    if (!u) {
      cout << dis / 2 << '\n';
      write(u);
      return;
    }
    for (int i = 0; i < 12; i++) {
      int x = (u >> i * 2) & 3;
      int cur = u - (x << i * 2) + (((x + 1) & 3) << i * 2);
      int nxt = f[i][x] - 1;
      int nxtx = (u >> nxt * 2) & 3;
      cur = cur - (nxtx << nxt * 2) + (((nxtx + 1) & 3) << nxt * 2);
      
      if (!prv[cur]) {
        Node node2 = {cur, dis + 2, h(cur)};
        prv[cur] = u;
        button[cur] = i + 1;

        q.push(node2);
      }
      if (!cur) {
        cout << (dis + 2) / 2 << '\n';
        write(cur);
        return;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}