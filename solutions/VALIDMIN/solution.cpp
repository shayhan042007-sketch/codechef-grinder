#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let x = min(A, B), y = min(B, C), z = min(C, A).
 * Without loss of generality, assume A <= B <= C.
 * Then:
 * min(A, B) = A
 * min(B, C) = B
 * min(C, A) = A
 * So, A = x, B = y, A = z.
 * This implies x = z.
 * 
 * More generally, if we have three values x, y, z representing min(A, B), min(B, C), min(C, A):
 * If we sort them such that x <= y <= z, then for a valid tuple to exist:
 * The two smallest values must be equal.
 * 
 * Proof:
 * Let the sorted values be v1 <= v2 <= v3.
 * If we set A = v2, B = v1, C = v3:
 * min(A, B) = min(v2, v1) = v1
 * min(B, C) = min(v1, v3) = v1
 * min(C, A) = min(v3, v2) = v2
 * So the set of minimums is {v1, v1, v2}.
 * This means the two smallest values must be equal.
 */

void solve() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    
    // After sorting, the two smallest values are arr[0] and arr[1].
    // They must be equal for a valid tuple to exist.
    if (arr[0] == arr[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}