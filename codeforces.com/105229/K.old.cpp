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
const int N = 1e6 + 7;
const int M = 2e6 + 7;
const int modN = 998244353;
const double PI = acos(-1);
mt19937_64 rng(time(0));

struct dat{
    ll len, sum, ans;
};

struct node{
    ll a, b;
    bool operator<(const node p)const{
        return b < p.b;
    }
} num[N];
void solve(){
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> num[i].a;
    for (int i = 1; i <= n;i++)
        cin >> num[i].b;
    sort(num + 1, num + 1 + n);
    ll tot = 0;
    vector<dat> v;
    for (int i = 1; i <= n;i++){
        tot = v.size();
        for (int j = 0; j < tot;j++){
            if(v[j].sum + num[i].a <= m)
                v.PB({v[j].len + 1, v[j].sum + num[i].a, v[j].ans + num[i].b * v[j].len});
        }
        if(num[i].a <= m)
            v.PB({1, num[i].a, 0});
    }
    ll ans = 0;
    for(auto [p, q, g]:v)
        ans = max(ans, g);
    cout << ans << "\n";
    std::cout << v.size() << '\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
// 1 2 3 4 5 6 7 8 9 10 11 12
// 4 8 12 16