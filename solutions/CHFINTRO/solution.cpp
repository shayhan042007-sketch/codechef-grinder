#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N contestants and a threshold rating r.
 * For each contestant with rating R:
 * - If R >= r, they are a "Good boi".
 * - If R < r, they are a "Bad boi".
 * 
 * Constraints:
 * N <= 1000
 * 1300 <= r, R <= 1501
 * Time complexity required: O(N)
 * Space complexity required: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long r;
    
    // Read N and r
    if (!(cin >> N >> r)) return 0;

    // Process each contestant
    for (int i = 0; i < N; ++i) {
        long long R;
        cin >> R;
        
        if (R >= r) {
            cout << "Good boi" << "\n";
        } else {
            cout << "Bad boi" << "\n";
        }
    }

    return 0;
}