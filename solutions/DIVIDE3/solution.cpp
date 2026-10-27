#include <iostream>

/**
 * Problem Analysis:
 * We have N toffees to be divided among 3 friends.
 * Let the number of toffees given to the three friends be a, b, and c.
 * We have a + b + c = N.
 * We want to minimize (max(a, b, c) - min(a, b, c)).
 * 
 * If N is divisible by 3, we can give N/3 to each friend.
 * Then max = N/3, min = N/3, imbalance = 0.
 * 
 * If N % 3 == 1, we can give (N/3), (N/3), and (N/3 + 1).
 * Then max = N/3 + 1, min = N/3, imbalance = 1.
 * 
 * If N % 3 == 2, we can give (N/3), (N/3 + 1), and (N/3 + 1).
 * Then max = N/3 + 1, min = N/3, imbalance = 1.
 * 
 * Thus, if N % 3 == 0, the answer is 0.
 * Otherwise, the answer is 1.
 * 
 * Note: The input format specifies a single integer N, not multiple test cases.
 */

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (std::cin >> n) {
        if (n % 3 == 0) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }
    
    return 0;
}