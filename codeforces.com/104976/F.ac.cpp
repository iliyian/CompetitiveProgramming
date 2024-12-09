#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

#define int long long
#define RI register int
#define CI const int &
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pi;
const int N = 1e6 + 5;
int n, q, x, y, z, u[N], v[N];
pi w[N];
vector<pi> E[N];
class FileInputOutput {
private:
  static const int S = 1 << 21;
#define tc()                                                                   \
  (A == B && (B = (A = Fin) + fread(Fin, 1, S, stdin), A == B) ? EOF : *A++)
#define pc(ch)                                                                 \
  (Ftop != Fend ? *Ftop++ = ch                                                 \
                : (fwrite(Fout, 1, S, stdout), *(Ftop = Fout)++ = ch))
  char Fin[S], Fout[S], *A, *B, *Ftop, *Fend;
  int pt[30];

public:
  inline FileInputOutput(void) {
    Ftop = Fout;
    Fend = Fout + S;
  }
  inline void read(int &x) {
    x = 0;
    char ch;
    while (!isdigit(ch = tc()))
      ;
    while (x = (x << 3) + (x << 1) + (ch & 15), isdigit(ch = tc()))
      ;
  }
  inline void write(int x, const char &ch = '\n') {
    if (!x)
      return (void)(pc('0'), pc(ch));
    RI ptop = 0;
    while (x)
      pt[++ptop] = x % 10, x /= 10;
    while (ptop)
      pc(pt[ptop--] + 48);
    pc(ch);
  }
  inline void flush(void) { fwrite(Fout, 1, Ftop - Fout, stdout); }
} F;
namespace LCA_Solver {
int dep[N], dis[N], seq[N], fir[N], f[N][20], _log[N], idx;
inline void DFS(CI now = 1, CI fa = 0) {
  seq[++idx] = now;
  fir[now] = idx;
  dep[now] = dep[fa] + 1;
  for (auto [to, w] : E[now])
    if (to != fa)
      dis[to] = dis[now] + w, DFS(to, now), seq[++idx] = now;
}
inline int mindep(CI x, CI y) { return dep[x] < dep[y] ? x : y; }
inline void init(void) {
  RI i, j;
  for (_log[0] = -1, i = 1; i <= idx; ++i)
    _log[i] = _log[i >> 1] + 1;
  for (i = 1; i <= idx; ++i)
    f[i][0] = seq[i];
  for (j = 1; j < 20; ++j)
    for (i = 1; i + (1 << j) - 1 <= idx; ++i)
      f[i][j] = mindep(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}
inline int LCA(int x, int y) {
  x = fir[x];
  y = fir[y];
  if (x > y)
    swap(x, y);
  int k = _log[y - x + 1];
  return mindep(f[x][k], f[y - (1 << k) + 1][k]);
}
inline int getdis(CI x, CI y) {
  if (x == 0 || y == 0)
    return 0;
  return dis[x] + dis[y] - 2LL * dis[LCA(x, y)];
}
}; // namespace LCA_Solver
using namespace LCA_Solver;
signed main() {
  // freopen("F.in","r",stdin); freopen("F.out","w",stdout);
  RI i;
  for (F.read(n), F.read(q), i = 1; i <= n; ++i)
    F.read(w[i].fi), w[i].se = i;
  for (i = 1; i < n; ++i)
    F.read(x), F.read(y), F.read(z), E[x].push_back(pi(y, z)),
        E[y].push_back(pi(x, z));
  DFS();
  init();
  int pos = n + 1;
  for (sort(w + 1, w + n + 1), i = 1; i <= n; ++i)
    if (w[i].fi != i - 1) {
      pos = i;
      break;
    }
  --pos;
  u[1] = u[2] = w[1].se;
  v[2] = w[2].se;
  for (i = 3; i <= pos; ++i) {
    int x = w[i].se, d0 = getdis(u[i - 1], v[i - 1]), d1 = getdis(u[i - 1], x),
        d2 = getdis(v[i - 1], x);
    if (d0 >= d1 && d0 >= d2)
      u[i] = u[i - 1], v[i] = v[i - 1];
    else if (d1 >= d0 && d1 >= d2)
      u[i] = u[i - 1], v[i] = x;
    else
      u[i] = x, v[i] = v[i - 1];
  }
  // for (i=1;i<=pos;++i) printf("%lld %lld %lld\n",w[i].se,u[i],v[i]);
  for (i = 1; i <= q; ++i) {
    F.read(x);
    F.read(y);
    auto check = [&](CI k) {
      return max(getdis(x, u[k + 1]), getdis(x, v[k + 1])) <= y;
    };
    int l = 0, r = pos - 1, mid, ret = pos;
    while (l <= r)
      if (check(mid = l + r >> 1))
        l = mid + 1;
      else
        ret = mid, r = mid - 1;
    F.write(ret);
  }
  return F.flush(), 0;
}