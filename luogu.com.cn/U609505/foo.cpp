#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128  = __int128_t;

/*------------------------------------------------------------*/
/* Fenwick 树（只存计数）                                     */
struct BIT {
    int n;
    vector<int64> t;                 // 计数不超过 2·10¹⁰，安全
    BIT(int n = 0) { init(n); }
    void init(int n_) { n = n_; t.assign(n + 1, 0); }
    // idx 为 0‑based
    void add(int idx, int64 v = 1) {
        for (++idx; idx <= n; idx += idx & -idx) t[idx] += v;
    }
    int64 sumPrefix(int idx) const {          // sum[0..idx]
        int64 s = 0;
        for (++idx; idx > 0; idx -= idx & -idx) s += t[idx];
        return s;
    }
    int64 sumRange(int l, int r) const {      // sum[l..r]
        if (l > r) return 0;
        return sumPrefix(r) - (l ? sumPrefix(l - 1) : 0);
    }
};
/*------------------------------------------------------------*/

struct Node {
    int idx;          // 前缀下标 i (0 … n)
    int64 P;          // Σ a
    int64 R;          // Σ a² - k*i
    i128 aux;         // P*P + i*R   （左式常数项）
};

int n;
int64 k;
vector<int64> a;

/* 全局变量（在递归里共享） */
vector<Node> nd;               // 前缀节点（含 i=0）
vector<i128> allAux;           // aux 的离散化表
BIT bit;
int64 answer = 0;

/*------------------------------------------------------------*/
/* CDQ 递归：统计区间 [l … r]（下标在 nd 中的下标） */
void cdq(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);

    /* 1) 把左右两段分别按 P（即前缀和）升序排列 */
    sort(nd.begin() + l, nd.begin() + mid + 1,
         [](const Node& A, const Node& B){ return A.P < B.P; });
    sort(nd.begin() + mid + 1, nd.begin() + r + 1,
         [](const Node& A, const Node& B){ return A.P < B.P; });

    /* 2) 双指针：左侧点 P ≤ 当前右点 P 时加入 BIT */
    int p = l;                                   // 左指针
    vector<int> inserted; inserted.reserve(mid - l + 1);
    for (int q = mid + 1; q <= r; ++q) {
        while (p <= mid && nd[p].P <= nd[q].P) {
            int pos = lower_bound(allAux.begin(), allAux.end(), nd[p].aux) - allAux.begin();
            bit.add(pos, 1);
            inserted.push_back(pos);             // 记住以后要删掉
            ++p;
        }
        // 右点 j 的阈值 T_j = P_j^2 + j*R_j
        i128 T = (i128)nd[q].P * nd[q].P + (i128)nd[q].idx * nd[q].R;

        // 统计 aux > T 的左点数
        int pos = upper_bound(allAux.begin(), allAux.end(), T) - allAux.begin(); // 第一个 > T
        if (pos < (int)allAux.size())
            answer += bit.sumRange(pos, (int)allAux.size() - 1);
    }

    /* 3) 清除本层插入的左点（恢复 BIT 为 0） */
    for (int pos : inserted) bit.add(pos, -1);
    inserted.clear();

    /* 4) 归并回原来的下标顺序，保证上层递归仍然按 idx 分段 */
    inplace_merge(nd.begin() + l, nd.begin() + mid + 1, nd.begin() + r + 1,
                 [](const Node& A, const Node& B){ return A.idx < B.idx; });
}

/*------------------------------------------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> k;

    /* 计算前缀和、平方和、R */
    vector<i128> pref(n + 1, 0), pref2(n + 1, 0), R(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pref[i]  = pref[i - 1] + (i128)a[i];
        pref2[i] = pref2[i - 1] + (i128)a[i] * a[i];
        R[i] = pref2[i] - (i128)k * i;          // R[i] = Σ a² - k·i
    }

    /* 建立节点（包括空前缀 i = 0） */
    nd.resize(n + 1);
    nd[0] = {0, 0, 0, (i128)0};
    for (int i = 1; i <= n; ++i) {
        int64 P = (int64)pref[i];               // 转成 64 位保存，范围安全
        int64 Ri = (int64)R[i];
        i128 aux = (i128)P * P + (i128)i * Ri;   // P² + i·R
        nd[i] = {i, P, Ri, aux};
    }

    /* 离散化所有 aux（因为 BIT 只能在离散坐标上操作） */
    allAux.reserve(n + 1);
    for (const auto &v : nd) allAux.push_back(v.aux);
    sort(allAux.begin(), allAux.end());
    allAux.erase(unique(allAux.begin(), allAux.end()), allAux.end());

    bit.init((int)allAux.size() + 2);

    cdq(0, n);

    cout << answer << '\n';
    return 0;
}