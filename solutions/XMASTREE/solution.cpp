#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef bought N trees for A rupees each (Total cost = N * A).
 * Chef sold M trees for B rupees each (Total revenue = M * B).
 * Profit = Total Revenue - Total Cost = (M * B) - (N * A).
 * 
 * Constraints:
 * 1 <= M <= N <= 100
 * 100 <= A <= B <= 1000
 * The result fits within a standard 32-bit integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, m, b;
    if (cin >> n >> a >> m >> b) {
        long long total_cost = n * a;
        long long total_revenue = m * b;
        long long profit = total_revenue - total_cost;
        
        cout << profit << endl;
    }
    
    return 0;
}