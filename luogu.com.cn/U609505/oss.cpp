#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    struct Node {
        long long sum;   // 区间和
        int mn, mx;      // 区间最小值、最大值
        int lazy;        // -1 表示没有懒标记
    };
    int n;
    vector<Node> t;

    SegTree(int _n = 0) { init(_n); }

    void init(int _n) {
        n = _n;
        t.assign(4 * n + 4, {});
        build(1, 1, n);
    }

    // 初始值 = 位置下标 i
    void build(int v, int l, int r) {
        t[v].lazy = -1;
        if (l == r) {
            t[v].sum = t[v].mn = t[v].mx = l;
            return;
        }
        int m = (l + r) >> 1;
        build(v << 1, l, m);
        build(v << 1 | 1, m + 1, r);
        pull(v);
    }

    void apply(int v, int val, int len) {
        t[v].sum = 1LL * val * len;
        t[v].mn = t[v].mx = val;
        t[v].lazy = val;
    }

    void push(int v, int l, int r) {
        if (t[v].lazy == -1) return;
        int m = (l + r) >> 1;
        apply(v << 1, t[v].lazy, m - l + 1);
        apply(v << 1 | 1, t[v].lazy, r - m);
        t[v].lazy = -1;
    }

    void pull(int v) {
        t[v].sum = t[v << 1].sum + t[v << 1 | 1].sum;
        t[v].mn  = min(t[v << 1].mn, t[v << 1 | 1].mn);
        t[v].mx  = max(t[v << 1].mx, t[v << 1 | 1].mx);
    }

    // 区间 chmax，所有元素提升到至少 val
    void range_chmax(int L, int R, int val) { range_chmax(1, 1, n, L, R, val); }

    void range_chmax(int v, int l, int r, int L, int R, int val) {
        if (L > r || R < l || t[v].mn >= val) return;          // 已经足够大
        if (L <= l && r <= R && t[v].mx <= val) {               // 全部 <= val
            apply(v, val, r - l + 1);
            return;
        }
        if (l == r) {                                          // 叶子
            // 此时一定是 mn < val < mx，实际只能把它提升到 val
            apply(v, val, 1);
            return;
        }
        push(v, l, r);
        int m = (l + r) >> 1;
        range_chmax(v << 1, l, m, L, R, val);
        range_chmax(v << 1 | 1, m + 1, r, L, R, val);
        pull(v);
    }

    long long total_sum() const { return t[1].sum; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        // 记录每个数值出现的位置，末尾加哨兵 n+1
        vector<vector<int>> pos(n + 2);
        for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);
        for (int v = 0; v <= n; ++v) pos[v].push_back(n + 1);

        SegTree seg(n);                     // 初始 M[l]=l
        long long ans = 0;
        long long totalPairs = 1LL * (n + 1) * n;   // (n+1)n

        for (int x = 0; x <= n; ++x) {
            int prev = 0;
            for (int p : pos[x]) {                 // 包含哨兵 n+1
                int L = prev + 1;
                int R = min(p, n);                 // p 可能是 n+1
                if (L <= R) seg.range_chmax(L, R, p);
                prev = p;
            }
            long long curSum = seg.total_sum();    // Σ M[l]
            long long Fx = totalPairs - curSum;     // F(x) = (n+1)n - ΣM
            ans += Fx;
        }
        cout << ans << '\n';
    }
    return 0;
}