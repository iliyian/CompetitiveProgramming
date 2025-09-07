#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

struct Frac {
    int n;
    int d;
    Frac(int n_, int d_) : n(n_), d(d_) {}
};

bool operator<(const Frac &l, const Frac &r) {
    return i64(l.n) * r.d < i64(r.n) * l.d;
}

void solve() {
    int m, k;
    std::cin >> m >> k;
    
    std::vector<int> t(k);
    for (int i = 0; i < k; i++) {
        std::cin >> t[i];
        t[i]--;
    }
    
    std::vector<int> c(m);
    for (int i = 0; i < m; i++) {
        std::cin >> c[i];
    }
    
    std::vector<int> ct(m);
    for (int i = 0; i < k; i++) {
        ct[t[i]]++;
    }
    
    {
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if (ct[i] > c[i]) {
                ok = false;
            }
        }
        
        if (!ok) {
            std::cout << m - std::count(c.begin(), c.end(), 0) << "\n";
            for (int i = 0; i < m; i++) {
                if (c[i]) {
                    std::cout << c[i] << " " << i + 1 << "\n";
                }
            }
            return;
        }
    }
    
    std::vector<int> x, len;
    for (int l = 0, r = 0; l < k; l = r) {
        while (r < k && t[l] == t[r]) {
            r++;
        }
        x.push_back(t[l]);
        len.push_back(r - l);
    }
    
    std::vector<std::vector<int>> vec(m);
    for (int i = 0; i < x.size(); i++) {
        vec[x[i]].push_back(i);
    }
    
    std::vector<int> val(x.size());
    for (int i = 0; i < x.size(); i++) {
        if (i + 1 < x.size() && x[i] < x[i + 1]) {
            val[i] = x.size() - i;
        } else {
            val[i] = -(x.size() - i);
        }
    }
    
    auto L = len;
    for (int v = 0; v < m; v++) {
        if (vec[v].empty()) {
            continue;
        }
        int step = c[v] - ct[v];
        std::priority_queue<std::tuple<Frac, int, int>> q;
        for (auto i : vec[v]) {
            q.emplace(Frac(L[i] + 1, L[i] - len[i] + 1), val[i], i);
        }
        while (step) {
            step--;
            auto [_, _1, i] = q.top();
            q.pop();
            
            L[i]++;
            q.emplace(Frac(L[i] + 1, L[i] - len[i] + 1), val[i], i);
        }
    }
    
    std::vector<std::pair<int, int>> ans;
    int j = 0;
    for (int i = 0; i < x.size(); i++) {
        while (j < x[i]) {
            if (c[j] && ct[j] == 0) {
                ans.emplace_back(c[j], j);
            }
            j++;
        }
        ans.emplace_back(L[i], x[i]);
    }
    while (j < m) {
        if (c[j] && ct[j] == 0) {
            ans.emplace_back(c[j], j);
        }
        j++;
    }
    
    std::cout << ans.size() << "\n";
    for (auto [l, x] : ans) {
        std::cout << l << " " << x + 1 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
