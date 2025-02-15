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
const ll INF = 1e18 + 7;
const int N = 1e6 + 7;
const int M = 5e8 + 7;
const int modN = 998244353;
const double PI = acos(-1);
mt19937_64 rng(time(0));

ll a[N], dis[N];
vector<ll> e[N], g[N];
vector<pll> E[N];
bool vis[N];
void solve(){
    ll s, e;
    cin >> s >> e;
    if(abs(e - s) > 180)
        e = e - 360;
    ll dis = e - s;
    if(s == e){
        cout << "0\n";
        cout << fixed << setprecision(10) << cos(s * PI / 180.0) << " " << sin(s * PI / 180.0) << "\n";
    }
    else if(abs(s - e) <= 90){
        cout << "2\n";
        cout << fixed << setprecision(10) << cos(s * PI / 180.0) << " " << sin(s * PI / 180.0) << "\n";
        double len = sqrt(2 - 2 * cos((180 - abs(dis)) * PI / 180.0));
        double mid = dis / 2.0 + s;
        cout << fixed << setprecision(10) << len * cos(mid * PI / 180.0) << " " << len * sin(mid * PI / 180.0) << "\n";
        cout << fixed << setprecision(10) << cos(e * PI / 180.0) << " " << sin(e * PI / 180.0) << "\n";
    }
    else if(abs(s - e) <= 131){
        cout << "3\n";
        cout << fixed << setprecision(10) << cos(s * PI / 180.0) << " " << sin(s * PI / 180.0) << "\n";
        double AD = sqrt(2 - 2 * cos(abs(dis) * PI / 180.0));
        double AH = (AD - 1.0) / 2.0;
        double A = acos(AH) / PI * 180 + (180 - abs(dis)) / 2.0;
        double W = (180 - A) / 2.0;
        double len = sqrt(2 - 2 * cos(A * PI / 180));
        if(e > s){
            cout << fixed << setprecision(10) << len * cos((s + W) * PI / 180.0) << " " << len * sin((s + W) * PI / 180.0) << "\n";
            cout << fixed << setprecision(10) << len * cos((e - W) * PI / 180.0) << " " << len * sin((e - W) * PI / 180.0) << "\n";
        }
        else{
            cout << fixed << setprecision(10) << len * cos((s - W) * PI / 180.0) << " " << len * sin((s - W) * PI / 180.0) << "\n";
            cout << fixed << setprecision(10) << len * cos((e + W) * PI / 180.0) << " " << len * sin((e + W) * PI / 180.0) << "\n";
        }
        cout << fixed << setprecision(10) << cos(e * PI / 180.0) << " " << sin(e * PI / 180.0) << "\n";
    }
    else{
        cout << "4\n";
        cout << fixed << setprecision(10) << cos(s * PI / 180.0) << " " << sin(s * PI / 180.0) << "\n";
        ll step;
        if(e > s){
            s += 90;
            step = 45;
        }
        else{
            s -= 90;
            step = -45;
        }
        dis = e - s;
        cout << fixed << setprecision(10) << sqrt(2) * cos((s - step) * PI / 180.0) << " " << sqrt(2) * sin((s - step) * PI / 180.0) << "\n";
        cout << fixed << setprecision(10) << cos(s * PI / 180.0) << " " << sin(s * PI / 180.0) << "\n";
        double len = sqrt(2 - 2 * cos((180 - abs(dis)) * PI / 180.0));
        double mid = dis / 2.0 + s;
        cout << fixed << setprecision(10) << len * cos(mid * PI / 180.0) << " " << len * sin(mid * PI / 180.0) << "\n";
        cout << fixed << setprecision(10) << cos(e * PI / 180.0) << " " << sin(e * PI / 180.0) << "\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}