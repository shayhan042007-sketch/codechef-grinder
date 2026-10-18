#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A consists only of 0s and 1s.
 * The operation is: pick adjacent elements A[i], A[i+1], add |A[i] - A[i+1]| to score,
 * and remove them.
 * 
 * Note that |A[i] - A[i+1]| is 1 if the pair is (0, 1) or (1, 0), and 0 if (0, 0) or (1, 1).
 * We want to maximize the number of (0, 1) or (1, 0) pairs we can form.
 * 
 * Let c0 be the total count of 0s and c1 be the total count of 1s.
 * Each operation removes two elements. 
 * If we pick a (0, 1) or (1, 0) pair, we remove one 0 and one 1.
 * If we pick a (0, 0) or (1, 1) pair, we remove two 0s or two 1s.
 * 
 * Since we want to maximize the number of pairs with difference 1, we want to 
 * maximize the number of (0, 1) pairs. Each such pair consumes one 0 and one 1.
 * The maximum number of such pairs we can possibly form is limited by the 
 * number of 0s and 1s available. Specifically, we can pair as many 0s with 1s 
 * as possible. The number of such pairs is min(c0, c1).
 * 
 * Can we always achieve min(c0, c1)?
 * Yes. Because we can always delete elements to bring any two elements together,
 * as long as we don't "trap" elements in a way that prevents pairing. 
 * However, in this specific problem, since we can pick ANY adjacent pair, 
 * we can always greedily pick a (0, 1) or (1, 0) pair if one exists. 
 * If no such pair exists, all remaining elements must be the same (all 0s or all 1s),
 * in which case the score contribution is 0.
 */

void solve() {
    int n;
    cin >> n;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) c0++;
        else c1++;
    }
    
    // The maximum score is simply the number of pairs of (0, 1) we can form.
    // Each pair (0, 1) or (1, 0) contributes 1 to the score.
    // We can form min(c0, c1) such pairs.
    cout << min(c0, c1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}