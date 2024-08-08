#include <iostream>
#include <queue>
#include <cassert>
#define int long long
using namespace std;
struct node {
  int id, num;
  bool operator<(const node &p) const { return num > p.num; }
};
priority_queue<node> q1, q2, q3, q4, q5;
int op1, op2 = 1, op3 = 1, op4, op5 = 2;
int n, w;
int a[300005], b[300005];
int ans[300005], sum;
signed main() {
  freopen("E.in", "r", stdin);
  freopen("E.ans", "w", stdout);
  cin >> n >> w;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
  for (int i = 1; i <= n; i++) {
    q1.push((node){i, a[i]});
    q4.push((node){i, b[i]});
  }
  for (int i = 1; i <= w; i++) {
    int minn = 1e10, op, p, q;
    while (!q1.empty() && ans[q1.top().id] != op1)
      q1.pop();
    if (!q1.empty() && q1.top().num < minn) {
      minn = q1.top().num;
      p = q1.top().id;
      op = 1;
    }
    while (!q2.empty() && ans[q2.top().id] != op2)
      q2.pop();
    if (!q2.empty() && q2.top().num < minn) {
      minn = q2.top().num;
      p = q2.top().id;
      op = 2;
    }
    while (!q3.empty() && ans[q3.top().id] != op3)
      q3.pop();
    while (!q4.empty() && ans[q4.top().id] != op4)
      q4.pop();
    if (!q3.empty() && !q4.empty() && q3.top().num + q4.top().num < minn) {
      minn = q3.top().num + q4.top().num;
      p = q3.top().id;
      q = q4.top().id;
      op = 3;
    }
    while (!q4.empty() && ans[q4.top().id] != op4)
      q4.pop();
    while (!q5.empty() && ans[q5.top().id] != op5)
      q5.pop();
    if (!q5.empty() && !q4.empty() && q5.top().num + q4.top().num < minn) {
      minn = q5.top().num + q4.top().num;
      p = q5.top().id;
      q = q4.top().id;
      op = 4;
    }
    sum += minn;
    assert(sum >= 0 && minn >= 0);
    if (op == 1) {
      ans[p] = 1;
      q2.push({p, b[p] - a[p]});
      q3.push({p, -a[p]});
    }
    if (op == 2) {
      ans[p] = 2;
      q5.push({p, a[p] - b[p]});
    }
    if (op == 3) {
      ans[p] = 0;
      ans[q] = 2;
      q1.push({p, a[p]});
      q4.push({p, b[p]});
      q5.push({q, a[q] - b[q]});
    }
    if (op == 4) {
      ans[p] = 1;
      ans[q] = 2;
      q2.push({p, b[p] - a[p]});
      q3.push({p, -a[p]});
      q5.push({q, a[q] - b[q]});
    }
  }
  cout << sum << endl;
  for (int i = 1; i <= n; i++)
    cout << ans[i];
  return 0;
}