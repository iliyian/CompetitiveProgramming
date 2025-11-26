#include <bits/stdc++.h>
using namespace std;

// Function to find a valid pair (x, y)
// where (a[j] % a[i]) is even
pair<int, int> findPair(const vector<int>& nums, int n) {
    int x = -1, y = -1;
    for (int i = 1; i <= min(10, n); i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((nums[j] % nums[i]) % 2 == 0) {
                x = nums[i];
                y = nums[j];
            }
        }
    }

    for (int i = n; i >= max(1, n - 10); i--) {
        for (int j = i - 1; j >= 1; j--) {
            if ((nums[i] % nums[j]) % 2 == 0) {
                y = nums[i];
                x = nums[j];
            }
        }
    }

    for (int i = 1; x == -1 && i <= n; i++) {
        if(nums[i] % 2 == 0) {
            if(y == -1) {
                y = nums[i];
            }
            else {
                x = nums[i];
                swap(x, y);
            }
        }
    }
    return {x, y};
}

// Function to handle each test case
void solve() {
    int n;
    cin >> n;

    // Input array (1-based)
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    // Find the pair
    pair<int, int> result = findPair(nums, n);

    // Print result
    if (result.first == -1) {
        cout << -1 << "\n";
    } else {
        cout << result.first << " " << result.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    // The code in the image is cut off here. 
    // Usually, a main function ends with return 0.
    return 0;
}