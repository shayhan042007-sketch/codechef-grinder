#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N and a secret code K of length M.
 * We need to find a substring of S of length M such that the cost to transform
 * it into K is minimized.
 * 
 * The cost to transform a digit 'a' to 'b' in a cyclic system (0-9) is:
 * diff = abs(a - b)
 * cost = min(diff, 10 - diff)
 * 
 * Since N <= 10^5 and M <= 10, we can iterate through all possible starting
 * positions i in S (from 0 to N-M) and calculate the cost to transform
 * S[i...i+M-1] into K.
 * 
 * Time Complexity: O(N * M) per test case.
 * Given sum of N <= 10^5 and M <= 10, total operations are ~10^6, which fits
 * well within the 1s time limit.
 */

int calculate_cost(char s_char, char k_char) {
    int s = s_char - '0';
    int k = k_char - '0';
    int diff = abs(s - k);
    return min(diff, 10 - diff);
}

void solve() {
    int N, M;
    cin >> N >> M;
    string S, K;
    cin >> S >> K;

    long long min_total_cost = -1;

    // Iterate through all possible substrings of S of length M
    for (int i = 0; i <= N - M; ++i) {
        long long current_cost = 0;
        for (int j = 0; j < M; ++j) {
            current_cost += calculate_cost(S[i + j], K[j]);
        }

        if (min_total_cost == -1 || current_cost < min_total_cost) {
            min_total_cost = current_cost;
        }
    }

    cout << min_total_cost << "\n";
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