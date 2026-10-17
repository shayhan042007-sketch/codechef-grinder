#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Current score is A : B, where A < B.
 * We want to play N more matches such that we can end up with a score (A + N) : B
 * where (A + N) > B.
 * 
 * To minimize N, we assume we win all N matches.
 * So, A + N > B
 * N > B - A
 * Since N must be an integer, the minimum N is (B - A) + 1.
 * 
 * Let's verify with sample cases:
 * 1. A=0, B=1: N > 1 - 0 => N > 1. Min N = 2. Correct.
 * 2. A=2, B=4: N > 4 - 2 => N > 2. Min N = 3. Correct.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run based on the 
    // input format description, but standard competitive programming practice 
    // often involves a test case count. Given the constraints and format:
    int A, B;
    if (cin >> A >> B) {
        int diff = B - A;
        int result = diff + 1;
        cout << result << "\n";
    }

    return 0;
}