#include <bits/stdc++.h>

using namespace std;

const int Ratio = 0;
const int N = 1e6 + 5;
const int maxx = 2e9;
int n, m;
int v[N << 1], sl[N << 1], sr[N << 1], L[25], R[25];

namespace Wisadel {
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) >> 1)
void Wbuild(int rt, int l, int r) {
  if (l == r)
    return;
  int ceng = log2(r - l + 1); // log2 自动向下取整
  Wbuild(ls, l, mid), Wbuild(rs, mid + 1, r);

  if (v[rt] == 1)
    sl[rt] = sl[ls] + sl[rs] + 1, sr[rt] = min(sr[ls], sr[rs]);
  else
    sl[rt] = min(sl[ls], sl[rs]), sr[rt] = sr[ls] + sr[rs] + 1;
  // 判断节点类型并进行更新

  L[ceng] = min(L[ceng], sl[rt]), R[ceng] = min(R[ceng], sr[rt]);
  // 更新每层范围
}
short main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= (1 << n) - 1; i++)
    scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++)
    L[i] = maxx, R[i] = maxx;
  Wbuild(1, 1, (1 << n));

  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    b -= 1;
    if (a > L[b] && (1 << n) - a >= R[b])
      printf("Yes\n");
    // 判断是否在范围内
    // (1<<n)-a>=R[b] 即为 (1<<n)-a+1>R[b]
    else
      printf("No\n");
  }
  return Ratio;
}
} // namespace Wisadel
int main() { return Wisadel::main(); }