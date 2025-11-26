#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 7;
int n;
struct node {int x, y;}a[MAXN], stk[MAXN];
double dis(node a, node b) {return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));}
double cross(node a, node b, node c) {return(b.x-a.x)*(c.y-a.y) - (c.x-a.x) * (b.y-a.y);}
double cmp(node a, node b) {return a.x != b.x ? a.x < b.x : a.y < b.y;}
int top = 0;
int ans = 0;
int dot(node a, node b, node c) {return (c.x-a.x) * (b.x-a.x) + (c.y-a.y) * (b.y-a.y);}
int nxt(int i) {
  if (i == top) return 1ll;
  return i + 1;
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  sort(a+1,a+1+n,cmp);
  for(int i = 1; i <= n; i++) {
    while(top > 1 && cross(stk[top-1],stk[top],a[i]) <= 0) top--;
    stk[++top] = a[i];
  }
  int temp = top;
  for(int i = n - 1; i >= 1; i--) { 
    while(top > temp && cross(stk[top-1],stk[top],a[i]) <= 0) top--;
    stk[++top] = a[i];
  }
  --top;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = 1, r = 1;
    int siz = top;
    for (int j = 1; j <= top; j++) {
      if (stk[j].x == a[i].x && stk[j].y == a[i].y) {
        siz--;
        l = r = nxt(i);
        break;
      }
    }
    for (int j = 0; j < siz; j++) {
      while (dot(a[i], stk[l], stk[nxt(r)]) < dot(a[i], stk[l], stk[r])) {
        r = nxt(r);
      }
      ans = std::min(ans, dot(a[i], stk[l], stk[r]));
      l = nxt(l);
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}