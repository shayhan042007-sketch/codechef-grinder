#include <bits/stdc++.h>

using namespace std;

/**
 * Problem Analysis:
 * Total apples = N, Total boxes = K.
 * Candidate 1: Puts 1 apple in each of the K boxes, repeating this N/K times.
 * Result 1: Every box gets exactly (N/K) apples.
 * 
 * Candidate 2: Puts K apples into one box at a time.
 * Total rounds = N/K. In each round, he picks a box with the smallest number of apples.
 * Since he adds K apples at once, he will fill boxes one by one.
 * Specifically, he will fill one box with K apples, then another with K, and so on.
 * After N/K rounds, he will have filled (N/K) boxes with K apples each, 
 * and the remaining boxes will have 0 apples.
 * 
 * The distributions are the same if and only if:
 * (N/K) apples in every box (Candidate 1) == (K apples in some boxes, 0 in others) (Candidate 2).
 * 
 * This happens if N/K = 0 (impossible as N >= K) or if N/K = K.
 * If N/K is not divisible by K, the distributions are definitely different.
 * If N/K is divisible by K, then N/K^2 is an integer.
 * Actually, let's re-evaluate:
 * Candidate 1 result: Each box has N/K.
 * Candidate 2 result: (N/K) boxes have K, others have 0.
 * 
 * They are the same if:
 * 1. If N/K = K, then each box has K apples (Candidate 1) and all boxes have K apples (Candidate 2).
 *    Wait, if N/K = K, then N = K^2. In this case, Candidate 2 fills every box with K apples.
 *    So if N/K is a multiple of K, the distributions are the same.
 *    If N/K is NOT a multiple of K, the distributions are different.
 * 
 * Example 1: N=5, K=1. N/K = 5. 5 is a multiple of 1. Output: NO. Correct.
 * Example 2: N=4, K=2. N/K = 2. 2 is a multiple of 2. Output: NO. Correct.
 * Example 3: N=10, K=10. N/K = 1. 1 is NOT a multiple of 10. Output: YES. Correct.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // The number of apples per box for candidate 1 is (n/k).
        // The distribution is the same if (n/k) is a multiple of k.
        // i.e., (n/k) % k == 0.
        
        long long apples_per_box = n / k;
        
        if (apples_per_box % k == 0) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }

    return 0;
}