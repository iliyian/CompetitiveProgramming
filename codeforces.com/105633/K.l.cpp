#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define fst first
#define scd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
using vi = vector<int>;
using vl = vector<ll>;
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 7;
const int M = 2e6 + 7;
const int modN = 1e9 + 7;
mt19937_64 rng(time(0));

void solve(){
    ll n, m;
    cin >> n >> m;
    ll tot = (1ll << m) - 1;
    vector<ll> a(tot + 1, n + 1), dp(tot + 1, 0);
    vector<ll> vis(tot + 1, n + 1);
    ll O = 0, P = n + 1, Q = n + 1;
    for (int i = 1; i <= n;i++){
        string s;
        cin >> s;
        ll cnt = 0;
        for (int j = 0; j < m;j++)
            cnt = cnt * 2 + (s[j] == 'Y');
        if(cnt == tot){
            O++;
            if(P > i){
                Q = P;
                P = i;
            }
            else if(Q > i)
                Q = i;
        }
        vis[cnt] = min(vis[cnt], (ll)i);

        cnt ^= tot;
        a[cnt] = min(a[cnt], (ll)i);
    }
    if(O >= 2){
        cout << P << " " << Q << "\n";
        return;
    }
    else if(O == 1){
        ll L = -1;
        for (int i = 0; i < tot;i++){
            if(vis[i] != n + 1){
                ll cur = i, num = 0;
                while(cur){
                    num++;
                    cur -= cur & -cur;
                }
                if(L < num){
                    L = num;
                    Q = vis[i];
                }
            }
        }
        if(P > Q)
            swap(P, Q);
        cout << P << " " << Q << "\n";
        return;
    }
    ll x = n + 1, y = n + 1, mx = -1;
    for (int i = 0; i <= tot;i++){
        for (int j = 0; j < m;j++){
            if((i & (1ll << j)) == 0){
                ll cur = (i | (1ll << j));
                if(dp[cur] < dp[i] + 1 && a[i] != n + 1){
                    dp[cur] = dp[i] + 1;
                    a[cur] = a[i];
                }
                else if(dp[cur] == dp[i] + 1)
                    a[cur] = min(a[cur], a[i]);
            }
            
        }
        if(vis[i] != n + 1 && a[i] != n + 1){
            if(dp[i] > mx){
                mx = dp[i];
                x = a[i];
                y = vis[i];
                if(x > y)
                    swap(x, y);
            }
            else if(dp[i] == mx){
                if(x > min(vis[i], a[i])){
                    x = vis[i], y = a[i];
                    if(x > y)
                        swap(x, y);
                }
                else if(x == min(vis[i], a[i]) && y > max(vis[i], a[i])){
                    y = max(vis[i], a[i]);
                }
            }
        }
        //cout << vis[i] << " " << a[i] << "\n";
        //cout << x << " " << y << "\n";
    }
    if(x > y)
        swap(x, y);
    if(x == n + 1 || y == n + 1)
        cout << "No\n";
    else
        cout << x << " " << y << "\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}