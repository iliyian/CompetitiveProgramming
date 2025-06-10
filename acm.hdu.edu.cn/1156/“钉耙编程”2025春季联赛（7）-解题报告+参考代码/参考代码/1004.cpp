#include <bits/stdc++.h>

using namespace std;

int n, q;

template<class Info>
struct SGT {
    int n;
    vector<Info> info;
    SGT() : n(0) {}
    SGT(int n_, Info v_ = Info()) { init(n_, v_); }
    template<class T>
    SGT(vector<T> init_) { init(init_); }
    void init(int n_, Info v_ = Info()) { init(vector(n_, v_)); }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) return info[p] = init_[l], void();
            int m = (l + r) >> 1;
            build(p << 1, l, m);
            build(p << 1 | 1, m + 1, r);
            pushup(p);
        };
        build(1, 1, --n);
    }
    void pushup(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void modify(int p, int l, int r, int x, const Info& v) {
        if (l == r) return info[p] = v, void();
        int m = (l + r) >> 1;
        if (x <= m) modify(p << 1, l, m, x, v);
        else modify(p << 1 | 1, m + 1, r, x, v);

        pushup(p);
    }
    void modify(int p, const Info& v) {
        modify(1, 1, n, p, v);
    }
    Info query(int p, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr) return info[p];
        int m = (l + r) >> 1;
        if (qr <= m) return query(p << 1, l, m, ql, qr);
        if (ql > m) return query(p << 1 | 1, m + 1, r, ql, qr);
        return query(p << 1, l, m, ql, qr) + query(p << 1 | 1, m + 1, r, ql, qr);
    }
    Info query(int l, int r) {
        return query(1, 1, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int ql, int qr, F&& pred) {
        if (l > qr || r < ql) return -1;
        if (l >= ql && r <= qr && !pred(info[p])) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = findFirst(p << 1, l, m, ql, qr, pred);
        if (res == -1) res = findFirst(p << 1 | 1, m + 1, r, ql, qr, pred);
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F&& pred) {
        return findFirst(1, 1, n, l, r, pred);
    }
};
struct Info {
    int v;
    Info() : v(0) {}
    Info(int x) : v(x) {}
    Info operator+(const Info& a) const {
        return Info(std::max(v, a.v));
    }
    explicit operator bool() const { return v != 0; }
    bool operator<(const Info& a) const { return v < a.v; }
    operator int() const { return v; }
};
struct F {
    int v;
    F() : v(0) {}
    F(int v_) : v(v_) {}
    bool operator()(const Info& a) {
        return a.v >= v;
    }
};

void solve() {
    string str;
    cin >> str;
    n = str.size(); str = " " + str;
    vector<Info> tab[2] {vector<Info>(n + 1), vector<Info>(n + 1)};
    set<int>pos;

    int sgn = (str[n] == '1'), cnt = 0;
    for (int i = n; i >= 1; --i) {
        ++cnt;
        if (str[i] != str[i - 1]) {
            tab[sgn][i] = cnt;
            pos.insert(i);
            cnt = 0;
            sgn ^= 1;
        }
    }

    SGT<Info> s[2] {tab[0], tab[1]};
    cin >> q;
    while (q--) {
        int op, k; cin >> op >> k; int  rv = op ^ 1;
        int ans = s[op].findFirst(1, n, F(k));
        cout << ans << '\n';
        if (ans == -1) continue;
        int len = k;
        if (ans + k <= n) {
            if (tab[rv][ans + k]) {
                len += tab[rv][ans + k];
                s[rv].modify(ans + k, 0);
                tab[rv][ans + k] = 0;
                pos.erase(ans + k);
            } else {
                pos.insert(ans + k);
                s[op].modify(ans + k, tab[op][ans] - k);
                tab[op][ans + k] = tab[op][ans] - k;
            }
        }
        if (ans > 1) {
            int prev = *(std::prev(pos.find(ans)));
            len += tab[rv][prev];
            s[op].modify(ans, 0);
            s[rv].modify(prev, len);
            tab[op][ans] = 0;
            tab[rv][prev] = len;
            pos.erase(ans);
        } else {
            s[rv].modify(ans, len); s[op].modify(ans, 0);
            tab[op][ans] = 0; tab[rv][ans] = len;
        }
    }
}
signed main(signed argc, char const* argv[]) {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int TxT = 1; cin >> TxT;
    while (TxT--)
        solve();
    return 0;
}
