#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The mayor can either invite people from regions A and C together, 
 * or invite people from region B alone.
 * 
 * Conflict constraints:
 * - B cannot be with A.
 * - B cannot be with C.
 * 
 * Valid sets:
 * - {A, C} -> Sum = P_A + P_C
 * - {B}    -> Sum = P_B
 * 
 * Result = max(P_A + P_C, P_B)
 */

void solve() {
    int pa, pb, pc;
    if (!(cin >> pa >> pb >> pc)) return;
    
    int option1 = pa + pc;
    int option2 = pb;
    
    cout << max(option1, option2) << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}