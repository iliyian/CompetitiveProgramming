#include <bits/stdc++.h>
using namespace std;

void solve(){
    int64_t d, r, x, y;
    cin >> d >> r >> x >> y;
    auto dis = [&](int64_t x1, int64_t y1, int64_t x2, int64_t y2){
        return sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    };
    if (y >= d){
        cout<<round(abs(dis(x, y, 0, d) - r))<<'\n';
        return;
    }
    if (y <= -d){
        cout<<round(abs(dis(x, y, 0, -d) - r))<<'\n';
        return;
    }
    cout<<min(abs(int64_t(x - r)), abs(int64_t(x + r)))<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}