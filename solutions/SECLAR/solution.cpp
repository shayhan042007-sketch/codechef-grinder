#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Find Second Largest
 * Approach: Read three integers from three separate lines, store in a vector,
 * sort, and output the middle element.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    
    // Reading the three integers from three separate lines
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;
    if (!(cin >> c)) return 0;

    vector<long long> v = {a, b, c};
    
    // Sorting the vector to easily identify the second largest
    sort(v.begin(), v.end());
    
    // The second largest element will be at index 1 after sorting
    cout << v[1] << endl;

    return 0;
}