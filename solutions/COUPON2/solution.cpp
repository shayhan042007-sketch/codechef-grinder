#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Cost without coupon: (SumA + D) + (SumB + D) = SumA + SumB + 2*D
 * - Cost with coupon: SumA + SumB + C + (delivery_charge_day1) + (delivery_charge_day2)
 *   - delivery_charge_day1 = (SumA >= 150) ? 0 : D
 *   - delivery_charge_day2 = (SumB >= 150) ? 0 : D
 * 
 * Chef buys the coupon if: Cost_with_coupon < Cost_without_coupon
 * 
 * Complexity:
 * - Time: O(T) where T is the number of test cases.
 * - Space: O(1) as we only store a few integer variables.
 */

void solve() {
    long long D, C;
    cin >> D >> C;
    
    long long A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    long long sumA = A1 + A2 + A3;
    
    long long B1, B2, B3;
    cin >> B1 >> B2 >> B3;
    long long sumB = B1 + B2 + B3;
    
    // Total cost without coupon
    long long costWithout = sumA + sumB + 2 * D;
    
    // Total cost with coupon
    long long deliveryDay1 = (sumA >= 150) ? 0 : D;
    long long deliveryDay2 = (sumB >= 150) ? 0 : D;
    long long costWith = sumA + sumB + C + deliveryDay1 + deliveryDay2;
    
    if (costWith < costWithout) {
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