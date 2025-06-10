#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N], pre[N], preBlk[N];
void solve() {
    int n, B, bias;
    cin >> n >> B >> bias;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    long long fz = 0, fm = 1;
    for (int st = 1; st <= B; ++st) {
        int totBlk = (n - st + 1) / B;
        preBlk[0] = pre[st - 1];
        for (int i = 1; i <= totBlk; ++i) {
            preBlk[i] = pre[i * B + st - 1];
        }
        preBlk[++totBlk] = pre[n];

        auto check = [&](double mid) {
            int l = 1;
            for (int i = 1; i <= totBlk; ++i) {
                if (preBlk[i - 1] - mid * (i - 1) < preBlk[l - 1] - mid * (l - 1))
                    l = i;
                if (preBlk[i] - mid * i > preBlk[l - 1] - mid * (l - 1) + mid * bias) {
                    return pair<int, int>{(l - 1) * B + st, min(n, st + i * B - 1)};
                }
            }
            return pair<int, int>{-1, -1};
        };

        double l = 0, r = pre[n];
        int L, R, cnt = 60;
        while (cnt--) {
            double mid = (l + r) / 2;
            auto [lt, rt] = check(mid);
            if (lt == -1 && rt == -1)
                r = mid;
            else {
                l = mid;
                L = lt, R = rt;
            }
        }
        // cout << st << " " << L << " " << R << " " << l << endl;
        long long nowFz = pre[R] - pre[L - 1], nowFm = bias + (int)ceil(1.0 * (R - L + 1) / B);
        if (1ll * fz * nowFm < 1ll * nowFz * fm) {
            fz = nowFz, fm = nowFm;
        }
    }
    long long g = __gcd(fz, fm);
    cout << fz / g << "/" << fm / g << endl;
}
int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
/*
2
4 3 1
10 1 1 10
10 3 2
3 10 1 2 9 8 1 8 5 8
*/