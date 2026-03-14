#include<bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        i64 x;
        std::cin >> n >> x;
        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        std::vector<i64> f(n + 1);
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + std::abs(a[i] - a[i - 1]);
        }
        if (f[n] <= x) {
            std::cout << 0 << "\n";
            continue;
        }
        int l = 2, r = n;
        auto check = [&](auto len) {
            std::deque<int> dq;
            auto add = [&](auto x) {
                while (dq.size() && dq.back() < x) {
                    dq.pop_back();
                }
                dq.push_back(x);
            };
            for (int i = 1; i < len; i++) {
                add(a[i]);
            }
            for (int i = len; i <= n; i++) {
                int j = i - len + 1;
                add(a[i]);
                if (dq.front() == a[j - 1]) dq.pop_front();
                int ma = dq.front();
                i64 sum = 0;
                if (j > 1) {
                    sum += f[j - 1];
                    sum += std::abs(ma - a[j - 1]);
                }
                if (i < n) {
                    sum += f[n] - f[i + 1];
                    sum += std::abs(ma - a[i + 1]);
                }
                if (sum <= x) return 1;
            }
            return 0;
        };
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        std::cout << l << "\n";
    }
}