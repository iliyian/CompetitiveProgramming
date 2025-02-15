#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> mp;
        long long ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum == 0) {
                ans++;
            }
            if (mp.contains(sum)) {
                ans += mp[sum];
            }
            mp[sum]++;
        }
        cout << ans << '\n';
    }
    return 0;
}