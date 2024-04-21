#include <bits/stdc++.h>
#define db double
using namespace std;
int n, cnt, tot, top, back;
db ans;
const db eps =
    1e-7; // 因为是实数范围，有精度误差，所以不能直接用“==”，而是取绝对值和一个很小的值进行比对。
struct node {
  db x, y;
  node() {}
  node(db _x, db _y) { x = _x, y = _y; }
  bool operator<(const node &t) const {
    return y < t.y || (y == t.y && x < t.x);
  }
  node operator-(node &t) { return node(x - t.x, y - t.y); }
  bool operator==(const node &t) const { return x == t.x && y == t.y; }
} _P, N[55], Ans[505]; // 存储点
db CPr(node A, node B) { return A.x * B.y - A.y * B.x; }
db CPr(node A, node B, node C) { return CPr(B - A, C - A); } // 向量叉积
struct edge {
  node start, end;
  db angle;
  edge() {}
  edge(node A, node B) {
    start = A, end = B;                  // 起点和终点
    angle = atan2((B - A).y, (B - A).x); // 极角
  }
  bool operator<(const edge &t) const {
    if (fabs(angle - t.angle) <= eps)
      return CPr(start, t.start, t.end) > 0; // 极角相同比位置
    return angle < t.angle;                  // 否则比极角
  }
} e[505], dq[505]; // 存储向量
db S1, S2;
node getnode(edge A, edge B) {
  S1 = CPr(A.start, B.end, A.end);
  S2 = CPr(A.start, B.start, A.end);
  return node((S1 * B.start.x - S2 * B.end.x) / (S1 - S2),
              (S1 * B.start.y - S2 * B.end.y) / (S1 - S2));
}
bool ch(edge A, edge B, edge C) {
  _P = getnode(B, C);
  return CPr(_P, A.start, A.end) < 0;
} // 求交点
signed main() {
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1, m; i <= n; i++) {
    scanf("%d", &m);
    for (int j = 1; j <= m; j++)
      scanf("%lf%lf", &N[j].x, &N[j].y);
    for (int j = 1; j <= m; j++)
      e[++cnt] = edge(N[j], N[j % m + 1]); // 读点，构建向量
  }
  sort(e + 1, e + cnt + 1); // 排序
  tot = 1;
  for (int i = 2; i <= cnt; i++)
    if (fabs(e[i].angle - e[i - 1].angle) > eps)
      e[++tot] = e[i]; // 去重
  top = 2, back = 1;
  dq[1] = e[1];
  dq[2] = e[2];
  for (int i = 3; i <= tot; i++) {
    while (back < top && ch(e[i], dq[top], dq[top - 1]))
      top--;
    while (back < top && ch(e[i], dq[back], dq[back + 1]))
      back++;
    dq[++top] = e[i]; // 增量
  }
  while (back < top && ch(dq[back], dq[top - 1], dq[top]))
    top--;
  while (back < top && ch(dq[top], dq[back], dq[back + 1]))
    back++; // 弹出不合法的向量
  for (int i = back; i < top; i++)
    Ans[i - back + 1] = getnode(dq[i], dq[i + 1]); // 求交点
  if (top - back > 1)
    Ans[top - back + 1] = getnode(dq[top], dq[back]);
  tot = top - back + 1;
  for (int i = 1; i <= tot; i++)
    ans += CPr(Ans[i], Ans[i % tot + 1]); // 算面积
  printf("%.3lf", fabs(ans) / 2);
  return 0;
}