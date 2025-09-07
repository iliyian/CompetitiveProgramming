#include<bits/stdc++.h>
#define ll long long
#define N 53
#define MAX_SIZE 45000
using namespace std;

// 交换两个元素的辅助函数
void swap(ll &a, ll &b) {
    ll temp = a;
    a = b;
    b = temp;
}

// 快速排序的分区函数
int partition(ll arr[], int low, int high) {
    ll pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// 快速排序实现
void quickSort(ll arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 手动实现的排序函数，替代std::sort
void manualSort(ll arr[], int size) {
    if (size <= 1) return; // 已经有序或为空
    quickSort(arr, 0, size - 1);
}

void solve() {
    int n;
    ll a[N], ans;
    ll b0[MAX_SIZE], b1[MAX_SIZE], b2[MAX_SIZE], b3[MAX_SIZE];
    int b0_size, b1_size, b2_size, b3_size;
    
    b0_size = 0;
    b1_size = 0;
    b2_size = 0;
    b3_size = 0;
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int len1 = n / 4, len2 = n / 4, len3 = n / 4, len4 = n - len1 - len2 - len3;
    bool flag;
    ll x = 0;
    
    // 处理第一部分
    for (int i = 0; i < (1 << len1); i++) {
        flag = 1;
        for (int j = 0; j < len1 - 1; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                flag = 0;
                break;
            }
        }
        x = 0;
        for (int j = 1; j <= len1; j++) {
            if ((i >> (j - 1)) & 1) x ^= a[j];
        }
        if (flag) {
            if (i & (1 << (len1 - 1))) b1[b1_size++] = x;
            else b0[b0_size++] = x;
        }
    }
    
    // 使用手动实现的排序替代std::sort
    manualSort(b0, b0_size);
    manualSort(b1, b1_size);
    
    // 内联去重
    if (b0_size > 1) {
        int k = 0;
        for (int i = 1; i < b0_size; i++) {
            if (b0[i] != b0[k]) {
                b0[++k] = b0[i];
            }
        }
        b0_size = k + 1;
    }
    
    if (b1_size > 1) {
        int k = 0;
        for (int i = 1; i < b1_size; i++) {
            if (b1[i] != b1[k]) {
                b1[++k] = b1[i];
            }
        }
        b1_size = k + 1;
    }
    
    // 处理第二部分
    for (int i = 0; i < (1 << len2); i++) {
        flag = 1;
        for (int j = 0; j < len2 - 1; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            x = 0;
            for (int j = 1; j <= len2; j++) {
                if ((i >> (j - 1)) & 1) x ^= a[len1 + j];
            }
            if (i & 1) {
                for (int k = 0; k < b0_size; k++) b3[b3_size++] = x ^ b0[k];
            } else {
                for (int k = 0; k < b0_size; k++) b2[b2_size++] = x ^ b0[k];
                for (int k = 0; k < b1_size; k++) b2[b2_size++] = x ^ b1[k];
            }
        }
    }
    b0_size = 0;
    b1_size = 0;
    
    // 使用手动实现的排序替代std::sort
    manualSort(b2, b2_size);
    manualSort(b3, b3_size);
    
    // 内联去重
    if (b2_size > 1) {
        int k = 0;
        for (int i = 1; i < b2_size; i++) {
            if (b2[i] != b2[k]) {
                b2[++k] = b2[i];
            }
        }
        b2_size = k + 1;
    }
    
    if (b3_size > 1) {
        int k = 0;
        for (int i = 1; i < b3_size; i++) {
            if (b3[i] != b3[k]) {
                b3[++k] = b3[i];
            }
        }
        b3_size = k + 1;
    }
    
    // 处理第三部分
    for (int i = 0; i < (1 << len3); i++) {
        flag = 1;
        for (int j = 0; j < len3 - 1; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            x = 0;
            for (int j = 1; j <= len3; j++) {
                if ((i >> (j - 1)) & 1) x ^= a[len1 + len2 + j];
            }
            if (i & 1) {
                for (int k = 0; k < b2_size; k++) b1[b1_size++] = x ^ b2[k];
            } else {
                for (int k = 0; k < b2_size; k++) b0[b0_size++] = x ^ b2[k];
                for (int k = 0; k < b3_size; k++) b0[b0_size++] = x ^ b3[k];
            }
        }
    }
    b2_size = 0;
    b3_size = 0;
    
    // 使用手动实现的排序替代std::sort
    manualSort(b0, b0_size);
    manualSort(b1, b1_size);
    
    // 内联去重
    if (b0_size > 1) {
        int k = 0;
        for (int i = 1; i < b0_size; i++) {
            if (b0[i] != b0[k]) {
                b0[++k] = b0[i];
            }
        }
        b0_size = k + 1;
    }
    
    if (b1_size > 1) {
        int k = 0;
        for (int i = 1; i < b1_size; i++) {
            if (b1[i] != b1[k]) {
                b1[++k] = b1[i];
            }
        }
        b1_size = k + 1;
    }
    
    // 处理第四部分
    for (int i = 0; i < (1 << len4); i++) {
        flag = 1;
        for (int j = 0; j < len4 - 1; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            x = 0;
            for (int j = 1; j <= len4; j++) {
                if ((i >> (j - 1)) & 1) x ^= a[len1 + len2 + len3 + j];
            }
            if (i & 1) {
                for (int k = 0; k < b0_size; k++) ans = max(ans, x ^ b0[k]);
            } else {
                for (int k = 0; k < b0_size; k++) ans = max(ans, x ^ b0[k]);
                for (int k = 0; k < b1_size; k++) ans = max(ans, x ^ b1[k]);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}