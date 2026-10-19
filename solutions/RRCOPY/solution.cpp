#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "Copy-Paste" operation allows us to take any contiguous subsequence and 
 * insert it anywhere. This means if we have a set of unique elements present 
 * in the final array A, we can always start with an initial array containing 
 * exactly those unique elements in any order. 
 * 
 * For example, if A = [1, 2, 3, 1, 2], the unique elements are {1, 2, 3}.
 * We can start with [1, 2, 3] and copy the subsequence [1, 2] to the end 
 * to get [1, 2, 3, 1, 2].
 * 
 * Since we want the minimal size of the initial array, and we must be able 
 * to generate every element present in A, the smallest possible initial 
 * array must contain every unique element of A exactly once.
 * 
 * Thus, the answer is simply the number of distinct elements in the array A.
 * 
 * Complexity:
 * Time: O(N log N) or O(N) depending on the set implementation. Given N=10^5,
 * O(N log N) using std::set or std::sort is well within the 2s time limit.
 * Space: O(N) to store the elements.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a set to count unique elements
    set<int> unique_elements;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        unique_elements.insert(val);
    }
    
    cout << unique_elements.size() << "\n";
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