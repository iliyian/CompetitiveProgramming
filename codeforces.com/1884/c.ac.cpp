#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, m, t;

struct node {
  int x, id;
  bool fl;
} a[N];

int b[N];
int d[N];
int c[N];
int ans;
int l[N], r[N];

bool cmp(node a, node b) { return a.x < b.x; }

// bool check(int x){
//     int res=0;
//     for(int i=1;i<=n;i++){
//         if(b[i]<=x&&b[i+n]>=x&&c[i+n]!=m){
//
//         }
//     }
// }

int main() {
  freopen("C.in", "r", stdin);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> l[i] >> r[i];
      a[i].x = l[i], a[i].fl = 1;
      a[i + n].x = r[i], a[i + n].fl = 0;
      a[i].id = i;
      a[i + n].id = i + n;
    }
    sort(a + 1, a + 1 + 2 * n, cmp);
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++) {
      if (a[i].x != a[i - 1].x) {
        b[a[i].id] = ++cnt;
      } else
        b[a[i].id] = cnt;
      c[a[i].id] = a[i].x;
      d[i] = 0;
    }


    
    for (int i = 1; i <= n; i++) {
      if (c[i + n] == m)
        continue;
      d[b[i]] += 1;
      d[b[i + n] + 1] -= 1;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<b[i]<<' '<<b[i+n]<<'\n';
    // }
    ans = 0;
    for (int i = 1; i <= cnt; i++) {
      d[i] += d[i - 1];
      ans = max(ans, d[i]);
      // cout<<d[i]<<' ';
    }
    for (int i = 1; i <= cnt; i++) {
      d[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (c[i] == 1)
        continue;
      d[b[i]] += 1;
      d[b[i + n] + 1] -= 1;
    }
    for (int i = 1; i <= cnt; i++) {
      d[i] += d[i - 1];
      ans = max(ans, d[i]);
    }
    // cout<<'\n';
    cout << ans << '\n';
    //        int l1=1,r1=cnt;
    //        while(l1<r1){
    //            int mid=(l1+r1)>>1;
    //            if(check(mid)){
    //
    //            }
    //            else{
    //
    //            }
    //        }
  }
}
/*
6 3
1 1
1 2
1 3
2 2
2 3
3 3
*/
/*
2 3
1 2
2 3
*/

/*
1
3 6
1 5
2 6
3 4
*/