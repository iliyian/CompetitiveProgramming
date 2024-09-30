#include <bits/stdc++.h> 
using namespace std;
 
#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
 
const int INF = 1000000005;
const int MAXN = 200005;
 
int t;
int n, x;
int a[MAXN], b[MAXN], aid[MAXN];
int ans[MAXN];
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("C.in", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        REP (i, 0, n) {
            cin >> a[i];
        }
        REP (i, 0, n) {
            cin >> b[i];
        }
        iota(aid, aid + n, 0);
        sort(aid, aid + n, [&] (int l, int r) {
                return a[l] < a[r];
                });
        sort(b, b + n);
        REP (i, 0, x) {
            ans[aid[n - x + i]] = b[i];
        }
        REP (i, x, n) {
            ans[aid[i - x]] = b[i];
        }
        REP (i, 0, n) {
            x -= a[i] > ans[i];
        }
        if (x == 0) {
            cout << "YES\n";
            REP (i, 0, n) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}