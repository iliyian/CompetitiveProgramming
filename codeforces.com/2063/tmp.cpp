#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 10;

int n, m, a[MAXN], b[MAXN];
int c[MAXN], d[MAXN], s1[MAXN], s2[MAXN];
int ans[MAXN];

bool check1(int i, int j){ return i + j * 2 <= m; }
bool check2(int i, int j){ return j + i * 2 <= n; }

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int n1 = n / 2, m1 = m / 2;
    for(int i = 1; i <= n1; ++i) c[i] = a[n + 1 - i] - a[i], s1[i] = s1[i - 1] + c[i];
    for(int i = 1; i <= m1; ++i) d[i] = b[m + 1 - i] - b[i], s2[i] = s2[i - 1] + d[i];
    int tot = 0;
    for(int i = 1, j = 0; ; ++i){
        while(i < n1 && j && !check1(i, j)) i++, j--;
        while(j < m1 && i && !check2(i, j)) i--, j++;
        if(!check1(i, j) || !check2(i, j)){ tot = i + j - 1; break; }
        while(i && j < m1 && check1(i - 1, j + 1) && check2(i - 1, j + 1) && c[i] < d[j + 1]) i--, j++;
        while(j && i < n1 && check1(i + 1, j - 1) && check2(i + 1, j - 1) && d[j] < c[i + 1]) i++, j--;
        ans[i + j] = s1[i] + s2[j];
    }
    cout << tot << '\n';
    for(int i = 1; i <= tot; ++i) cout << ans[i] << ' '; cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T; cin >> T; while(T--) solve();

    return 0;
}