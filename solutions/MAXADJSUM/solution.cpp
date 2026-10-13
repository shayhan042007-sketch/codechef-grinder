#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(A) = (A_1 + A_2) + (A_2 + A_3) + ... + (A_{N-1} + A_N)
 * f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
 * 
 * To maximize this sum, we want the largest elements to have a coefficient of 2.
 * The two smallest elements should be placed at the ends (A_1 and A_N) so that 
 * they are counted only once, while all other N-2 elements are counted twice.
 * 
 * Let the sorted array be S_1 <= S_2 <= ... <= S_N.
 * The maximum sum is:
 * f(A) = S_1 + S_N + 2 * (S_2 + S_3 + ... + S_{N-1})
 * Alternatively, this is:
 * f(A) = 2 * (Sum of all elements) - (S_1 + S_N)
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    sort(A.begin(), A.end());
    
    // The two smallest elements are A[0] and A[1].
    // To maximize the sum, we place the two smallest elements at the ends.
    // The sum becomes 2 * (total_sum) - (A[0] + A[1]).
    // Wait, let's re-verify:
    // The formula is: A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
    // To maximize this, we want the largest values to be multiplied by 2.
    // The smallest values should be at the ends.
    // So, A_1 = S_1, A_N = S_2, and the rest are S_3...S_N.
    // Sum = S_1 + S_2 + 2 * (S_3 + ... + S_N)
    // Which is equivalent to 2 * (Sum of all) - (S_1 + S_2).
    
    long long result = 2 * total_sum - (A[0] + A[1]);
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}