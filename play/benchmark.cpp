#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <random>
#include <algorithm>

// 包含所有三个库的头文件
#include <gmpxx.h>
#include <boost/multiprecision/gmp.hpp>
#include "Integer.h"

// --- 全局配置 ---
const int DIGIT_COUNT_A = 10000000;      // <<-- 被除数的位数
const int DIGIT_COUNT_B = 5000000;      // <<-- 除数的位数 (A的一半)
const int FAST_OP_ITERATIONS = 10;      // 加减法循环次数
const int SLOW_OP_ITERATIONS = 5;       // 乘除法循环次数 (因为除法会很慢，所以次数减少)

// --- 工具类和函数 ---

class Timer {
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}
    void reset() { start_time = std::chrono::high_resolution_clock::now(); }
    double elapsed_ms() const {
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::milli>(end_time - start_time).count();
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

void generate_large_number_str(std::string& s, int num_digits, std::mt19937& rng) {
    if (num_digits <= 0) {
        s = "0";
        return;
    }
    s.resize(num_digits);
    std::uniform_int_distribution<int> dist(0, 9);
    s[0] = (dist(rng) % 9 + 1) + '0'; // 首位不为0
    for (int i = 1; i < num_digits; ++i) {
        s[i] = dist(rng) + '0';
    }
}

void generate_test_data(const std::string& filename, int num_digits_a, int num_digits_b) {
    std::cout << "Generating two random numbers with " << num_digits_a << " and " << num_digits_b << " digits..." << std::endl;
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Error: Cannot create file " << filename << std::endl;
        return;
    }
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::string num_str;

    generate_large_number_str(num_str, num_digits_a, rng);
    ofs << num_str << '\n';

    generate_large_number_str(num_str, num_digits_b, rng);
    ofs << num_str << '\n';

    ofs.close();
    std::cout << "File '" << filename << "' has been generated." << std::endl;
}

// --- 主程序 ---
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);

    const std::string number_file = "numbers.txt";

    generate_test_data(number_file, DIGIT_COUNT_A, DIGIT_COUNT_B);
    std::cout << "--------------------------------------------------\n" << std::endl;

    std::cout << "Reading numbers from '" << number_file << "'..." << std::endl;
    std::ifstream ifs(number_file);
    if (!ifs) {
        std::cerr << "Error: Cannot open '" << number_file << "'." << std::endl;
        return 1;
    }
    std::string str_a, str_b;
    ifs >> str_a >> str_b;
    ifs.close();
    std::cout << "Numbers loaded. Number of digits: " << str_a.length() << " and " << str_b.length() << std::endl;
    std::cout << "--------------------------------------------------\n" << std::endl;

    // --- 2. GMP 测试 ---
    {
        std::cout << "--- Benchmarking GMP (gmpxx) ---" << std::endl;
        Timer t;
        mpz_class gmp_a(str_a), gmp_b(str_b);
        std::cout << "Parsing: " << std::fixed << std::setprecision(4) << t.elapsed_ms() << " ms\n";
        
        t.reset(); mpz_class res_add; for (int i = 0; i < FAST_OP_ITERATIONS; ++i) { res_add = gmp_a + gmp_b; }
        std::cout << "Addition (x" << FAST_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";
        
        t.reset(); mpz_class res_sub; for (int i = 0; i < FAST_OP_ITERATIONS; ++i) { res_sub = gmp_a - gmp_b; }
        std::cout << "Subtraction (x" << FAST_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";

        t.reset(); mpz_class res_mul; for (int i = 0; i < SLOW_OP_ITERATIONS; ++i) { res_mul = gmp_a * gmp_b; }
        std::cout << "Multiplication (x" << SLOW_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";

        // 【最终修正】除法
        t.reset(); mpz_class res_div; for (int i = 0; i < SLOW_OP_ITERATIONS; ++i) { res_div = gmp_a / gmp_b; }
        std::cout << "Division (x" << SLOW_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";
        
        t.reset(); volatile std::string str = res_mul.get_str();
        std::cout << "Formatting (multiplication result): " << t.elapsed_ms() << " ms\n";
        std::cout << "--------------------------------------------------\n" << std::endl;
    }

    // --- 3. Boost.Multiprecision 测试 ---
    {
        namespace mp = boost::multiprecision;
        using boost_gmp = mp::number<mp::gmp_int>;

        std::cout << "--- Benchmarking Boost.Multiprecision (GMP backend) ---" << std::endl;
        Timer t;
        boost_gmp boost_a(str_a), boost_b(str_b);
        std::cout << "Parsing: " << std::fixed << std::setprecision(4) << t.elapsed_ms() << " ms\n";

        t.reset(); boost_gmp res_add; for (int i = 0; i < FAST_OP_ITERATIONS; ++i) { res_add = boost_a + boost_b; }
        std::cout << "Addition (x" << FAST_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";

        t.reset(); boost_gmp res_sub; for (int i = 0; i < FAST_OP_ITERATIONS; ++i) { res_sub = boost_a - boost_b; }
        std::cout << "Subtraction (x" << FAST_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";

        t.reset(); boost_gmp res_mul; for (int i = 0; i < SLOW_OP_ITERATIONS; ++i) { res_mul = boost_a * boost_b; }
        std::cout << "Multiplication (x" << SLOW_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";
        
        // 【最终修正】除法
        t.reset(); boost_gmp res_div; for (int i = 0; i < SLOW_OP_ITERATIONS; ++i) { res_div = boost_a / boost_b; }
        std::cout << "Division (x" << SLOW_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";
        
        t.reset(); volatile std::string str = res_mul.str();
        std::cout << "Formatting (multiplication result): " << t.elapsed_ms() << " ms\n";
        std::cout << "--------------------------------------------------\n" << std::endl;
    }

    // --- 4. 自定义 Integer.h 测试 ---
    {
        std::cout << "--- Benchmarking Custom Integer.h ---" << std::endl;
        Timer t;
        SignedInteger custom_a(str_a), custom_b(str_b);
        std::cout << "Parsing: " << std::fixed << std::setprecision(4) << t.elapsed_ms() << " ms\n";

        t.reset(); SignedInteger res_add; for (int i = 0; i < FAST_OP_ITERATIONS; ++i) { res_add = custom_a + custom_b; }
        std::cout << "Addition (x" << FAST_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";
        
        t.reset(); SignedInteger res_sub; for (int i = 0; i < FAST_OP_ITERATIONS; ++i) { res_sub = custom_a - custom_b; }
        std::cout << "Subtraction (x" << FAST_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";
        
        t.reset(); SignedInteger res_mul; for (int i = 0; i < SLOW_OP_ITERATIONS; ++i) { res_mul = custom_a * custom_b; }
        std::cout << "Multiplication (x" << SLOW_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";
        
        // (无需修正，但现在会测试一个更真实的场景)
        t.reset(); SignedInteger res_div; for (int i = 0; i < SLOW_OP_ITERATIONS; ++i) { res_div = custom_a / custom_b; }
        std::cout << "Division (x" << SLOW_OP_ITERATIONS << "): " << t.elapsed_ms() << " ms\n";

        t.reset(); volatile std::string str = static_cast<std::string>(res_mul);
        std::cout << "Formatting (multiplication result): " << t.elapsed_ms() << " ms\n";
        std::cout << "--------------------------------------------------\n" << std::endl;
    }

    return 0;
}