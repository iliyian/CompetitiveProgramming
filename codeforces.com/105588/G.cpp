#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
#define int long long
int gcd(int a,int b) {return b ? gcd(b,a % b) : a;}
struct node {
  int x,y,num;
};
void solve() {
  int a,b;
  cin >> a >> b;
  queue<node> q;
  q.push({a,b,0});
  while(!q.empty()) { 
    node tem = q.front(); q.pop();
    int x = tem.x, y = tem.y,d = tem.num;
    int tx,ty;
    tx = x - gcd(x,y); ty = y;
    if(tx == 0 && ty == 0) {
      cout << d + 1;
      return;
    }
    if(tx >= 0 && ty >= 0) q.push({tx,ty,d+1});
    tx = x; ty = y - gcd(x,y);
    if(tx == 0 && ty == 0) {
      cout << d + 1;
      return;
    }
    if(tx >= 0 && ty >= 0) q.push({tx,ty,d+1});
  }
}

signed main() {
//  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
