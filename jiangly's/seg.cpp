#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Info {
    int max = 0;
};

Info operator+(const Info &a, const Info &b) {
    return Info {std::max(a.max, b.max)};
}

constexpr int N = 1 << 21;

SegmentTree<Info> seg(N);

void solve() {
    int n;
    std::cin >> n;
    
    std::set<int> s {0, 2 * N};
    seg.modify(1, {2 * N - 1});
    
    auto insert = [&](int x) {
        auto it = s.insert(x).first;
        auto l = std::prev(it);
        auto r = std::next(it);
        seg.modify(*l + 1, {x - *l - 1});
        seg.modify(x + 1, {*r - x - 1});
    };
    
    auto erase = [&](int x) {
        auto it = s.find(x);
        auto l = std::prev(it);
        auto r = std::next(it);
        seg.modify(*l + 1, {*r - *l - 1});
        seg.modify(x + 1, {});
        s.erase(it);
    };
    
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        insert(a);
    }
    
    int m;
    std::cin >> m;
    
    while (m--) {
        std::string op;
        int x;
        std::cin >> op >> x;
        
        if (op == "+") {
            insert(x);
        } else if (op == "-") {
            erase(x);
        } else {
            std::cout << seg.findFirst(0, N,
                [&](const auto &s) {
                    return s.max >= x;
                }) << " ";
        }
    }
    std::cout << "\n";
    
    for (auto x : s) {
        if (x < N) {
            seg.modify(x + 1, {});
        }
    }
    
}
