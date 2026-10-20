#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to arrange numbers from 1 to N such that no two adjacent elements 
 * have a product that is a perfect square.
 * 
 * A simple strategy is to output the numbers in reverse order: N, N-1, ..., 1.
 * Let's check if this works for small N.
 * For N=2: 2, 1 (2*1=2, ok)
 * For N=3: 3, 2, 1 (3*2=6, 2*1=2, ok)
 * For N=4: 4, 3, 2, 1 (4*3=12, 3*2=6, 2*1=2, ok)
 * For N=5: 5, 4, 3, 2, 1 (5*4=20, 4*3=12, 3*2=6, 2*1=2, ok)
 * For N=6: 6, 5, 4, 3, 2, 1 (6*5=30, 5*4=20, 4*3=12, 3*2=6, 2*1=2, ok)
 * 
 * Wait, what if N=8? 8, 7, 6, 5, 4, 3, 2, 1
 * 8*2 = 16 (Perfect square!)
 * So, simply reversing is not always sufficient.
 * 
 * A more robust approach:
 * Separate numbers into two groups:
 * Group 1: Odd numbers
 * Group 2: Even numbers
 * 
 * If we place all odd numbers first, then all even numbers, the only potential 
 * issue is the transition point. However, even if we just output 1, 2, ..., N,
 * we can check if the condition is violated.
 * 
 * Actually, for N up to 500, we can use a simple greedy approach with backtracking 
 * or a randomized shuffle. Given the constraints and the nature of the problem, 
 * a simple shuffle until the condition is met will be extremely fast.
 */

bool is_perfect_square(int n) {
    int root = round(sqrt(n));
    return root * root == n;
}

bool check(const vector<int>& p) {
    for (size_t i = 0; i < p.size() - 1; ++i) {
        if (is_perfect_square(p[i] * p[i + 1])) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    
    // Random shuffle is very likely to find a valid permutation quickly
    // for N <= 500.
    mt19937 rng(1337);
    while (!check(p)) {
        shuffle(p.begin(), p.end(), rng);
    }
    
    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}