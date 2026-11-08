#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The die has N faces. Each face has a value x_i.
 * The probability of getting a specific value 'v' in one toss is:
 * P(v) = (count of faces with value v) / N
 * 
 * Since the two tosses are independent, the probability of getting A on the first
 * toss and B on the second toss is:
 * P(Win) = P(A) * P(B)
 * P(Win) = (count of A / N) * (count of B / N)
 * P(Win) = (count of A * count of B) / (N * N)
 * 
 * Constraints:
 * N <= 10^4, T <= 70.
 * An O(N) approach per test case is well within the 0.5s time limit.
 */

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;
    
    vector<int> x(N);
    long long countA = 0;
    long long countB = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        if (x[i] == A) {
            countA++;
        }
        if (x[i] == B) {
            countB++;
        }
    }
    
    // Calculate probability
    // Use double for precision as required by the problem
    double probA = (double)countA / N;
    double probB = (double)countB / N;
    double result = probA * probB;
    
    cout << fixed << setprecision(10) << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}