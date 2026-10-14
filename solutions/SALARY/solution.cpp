#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N workers with salaries W_i.
 * An operation consists of choosing one worker and increasing everyone else's salary by 1.
 * This is equivalent to saying: the chosen worker's salary remains the same, 
 * while everyone else's salary increases by 1.
 * 
 * Let the target equal salary be S. Since we can only increase salaries, 
 * S must be at least the maximum salary currently in the array.
 * However, notice that increasing everyone except one worker by 1 is equivalent 
 * to decreasing that one worker's salary relative to the others.
 * 
 * Let the sum of all salaries be Sum and the minimum salary be Min.
 * In each operation, we increase N-1 workers by 1.
 * After K operations, the total sum of salaries will be Sum + K * (N - 1).
 * If all salaries become equal to some value X, then the total sum will be N * X.
 * 
 * A simpler observation:
 * Increasing everyone except worker i by 1 is equivalent to decreasing worker i 
 * by 1 relative to the others. To make all salaries equal to the minimum salary 
 * is impossible because we can only increase. To make all salaries equal to the 
 * current maximum is also not quite right.
 * 
 * Actually, the operation "increase all except one" is mathematically equivalent 
 * to "decrease one" if we look at the differences between salaries.
 * The total number of operations to make all W_i equal to min(W_i) 
 * is simply the sum of (W_i - min(W_i)) for all i.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long min_val = 20000; // Larger than max constraint 10000
    long long sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] < min_val) {
            min_val = w[i];
        }
        sum += w[i];
    }
    
    // The number of operations required is the sum of differences 
    // between each salary and the minimum salary.
    long long operations = 0;
    for (int i = 0; i < n; ++i) {
        operations += (w[i] - min_val);
    }
    
    cout << operations << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}