#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given the condition: A_i - A_j = i - j
 * Rearranging the terms:
 * A_i - i = A_j - j
 * 
 * Let B_k = A_k - k for all 1 <= k <= N.
 * The condition becomes B_i = B_j for i < j.
 * 
 * We need to count the number of pairs (i, j) such that i < j and B_i = B_j.
 * This is equivalent to counting the number of pairs with the same value in array B.
 * If a value 'x' appears 'count' times in array B, the number of pairs is 
 * count * (count - 1) / 2.
 */

void solve() {
    int N;
    cin >> N;
    
    // Using a map to store the frequency of (A_i - i)
    // Since A_i is up to N and i is up to N, A_i - i ranges from (1 - N) to (N - 1).
    // A map or an unordered_map is suitable. Given N <= 4*10^4, 
    // a map is efficient enough.
    map<int, long long> freq;
    
    for (int i = 1; i <= N; ++i) {
        int val;
        cin >> val;
        int diff = val - i;
        freq[diff]++;
    }
    
    long long total_pairs = 0;
    for (auto const& [val, count] : freq) {
        if (count >= 2) {
            total_pairs += (count * (count - 1)) / 2;
        }
    }
    
    cout << total_pairs << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}