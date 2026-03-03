#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstring>
#include <ctime>

using namespace std;

// 存储最终结果
int grid[9][9];
// 列掩码：col_mask[col] 的第 k 位为1，表示该列已填入数字 k
int col_mask[9];
bool solved = false;

struct Candidate {
    int digits[9];
};
vector<Candidate> cands;

// 辅助函数：将数值分解为9位数字
// 关键优化：根据提示"缺8数"，如果包含数字8直接返回false
// 同时检查是否有重复数字
inline bool check_and_parse(long long val, int* out_digits) {
    int mask = 0;
    // 从低位到高位解析
    for (int i = 8; i >= 0; --i) {
        int d = val % 10;
        val /= 10;
        
        // 【关键剪枝】根据提示：缺8数。如果出现8，直接不符合要求
        if (d == 8) return false;
        
        // 检查重复数字
        if ((mask >> d) & 1) return false;
        
        mask |= (1 << d);
        out_digits[i] = d;
    }
    return true;
}

// 深度优先搜索
// 这里的回溯会非常快，因为所有候选行的数字集合都是一样的（没有8），
// 只要位置不冲突即可，极易找到解。
void dfs(int row) {
    if (solved) return;
    if (row == 9) {
        solved = true;
        return;
    }

    // 遍历候选行
    for (const auto& cand : cands) {
        // 检查列冲突
        // 展开循环进行位运算检查，速度最快
        if ( ((col_mask[0] >> cand.digits[0]) & 1) |
             ((col_mask[1] >> cand.digits[1]) & 1) |
             ((col_mask[2] >> cand.digits[2]) & 1) |
             ((col_mask[3] >> cand.digits[3]) & 1) |
             ((col_mask[4] >> cand.digits[4]) & 1) |
             ((col_mask[5] >> cand.digits[5]) & 1) |
             ((col_mask[6] >> cand.digits[6]) & 1) |
             ((col_mask[7] >> cand.digits[7]) & 1) |
             ((col_mask[8] >> cand.digits[8]) & 1) ) {
            continue;
        }

        // 填入
        for(int j=0; j<9; ++j) {
            col_mask[j] |= (1 << cand.digits[j]);
            grid[row][j] = cand.digits[j];
        }

        dfs(row + 1);
        if (solved) return;

        // 回溯
        for(int j=0; j<9; ++j) {
            col_mask[j] &= ~(1 << cand.digits[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mt19937 rng(time(0));
    
    // 题目要求 GCD > 400,000
    long long D = 400001;
    
    // 最小的9位不含8且互不相同的数大约是 012345679 (即 12345679)
    // 最大的数是 976543210
    const long long MIN_VAL = 12345679;
    const long long MAX_VAL = 976543210;

    int temp_digits[9];

    while (!solved) {
        cands.clear();
        
        // 找到当前D的倍数起点
        long long start = (MIN_VAL + D - 1) / D * D;
        if (start < MIN_VAL) start += D;

        // 遍历所有倍数
        for (long long val = start; val <= MAX_VAL; val += D) {
            if (check_and_parse(val, temp_digits)) {
                cands.push_back(Candidate{});
                memcpy(cands.back().digits, temp_digits, 9 * sizeof(int));
            }
        }

        // 如果候选数太少，很难凑成9x9，直接跳过
        // 加了"缺8"约束后，符合条件的数更稀疏，如果能找到9个以上，通常就能解出来
        if (cands.size() >= 9) {
            // 打乱顺序，增加随机性
            shuffle(cands.begin(), cands.end(), rng);
            
            memset(col_mask, 0, sizeof(col_mask));
            dfs(0);
        }
        
        if (!solved) {
            D++;
        }
    }

    // 输出
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << grid[i][j] << (j == 8 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}