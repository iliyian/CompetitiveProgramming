#include<bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int k = 2;
        std::vector<int> a(n + 1), d = a;
        std::vector g(2, std::vector<int>());
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        n--;
        for (int i = 1; i <= n; i++) {
            d[i] = a[i] - a[i - 1] - 1;
            g[(i - 1) % k].push_back(d[i]);
        }
        int res = 0;
        for (auto& v : g) {
            int len = v.size();
            len--;
            for (int i = len; i >= 0; i -= 2) {
                res ^= v[i];
            }
        }
        if (res) std::cout << "Taki" << "\n";
        else std::cout << "Maki" << "\n";
    }
}