#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The length Ni must be odd for a unique center to exist.
 *    If Ni is even, it's impossible to have an equal number of parts on both sides.
 * 2. The first element H[0] must be 1.
 * 3. The last element H[Ni-1] must be 1.
 * 4. The sequence must increase by 1 until the center, then decrease by 1.
 *    This implies H[i] = i + 1 for 0 <= i <= center_index
 *    And H[i] = (Ni - 1 - i) + 1 for center_index < i < Ni
 */

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Condition 1: Length must be odd
    if (n % 2 == 0) {
        cout << "no" << "\n";
        return;
    }

    // Condition 2: Start and end must be 1
    if (h[0] != 1 || h[n - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int center = n / 2;
    
    // Check increasing part and decreasing part
    for (int i = 0; i < n; ++i) {
        if (i <= center) {
            // Should be 1, 2, 3, ..., center+1
            if (h[i] != i + 1) {
                cout << "no" << "\n";
                return;
            }
        } else {
            // Should be center, ..., 1
            // Distance from end is (n - 1 - i)
            // So height should be (n - 1 - i) + 1
            if (h[i] != (n - i)) {
                cout << "no" << "\n";
                return;
            }
        }
    }

    cout << "yes" << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    cin >> s;
    while (s--) {
        solve();
    }
    return 0;
}