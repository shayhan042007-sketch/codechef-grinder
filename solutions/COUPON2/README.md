# [Chef and Coupon (COUPON2)](https://www.codechef.com/problems/COUPON2)

- **Difficulty Rating**: 1222
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to order food for two days. Each day, he orders three items. There is a delivery charge $D$ for each order unless the total cost of items on that day is at least $150$. Chef can purchase a coupon for $C$ cost, which makes the delivery charge $0$ for both days, but he still has to pay the coupon price. We need to determine if buying the coupon is strictly cheaper than not buying it.

## Intuition & Mathematical Observation
To decide whether to buy the coupon, we compare the total cost in two scenarios:

1.  **Without Coupon:**
    *   Cost = (Sum of items on Day 1 + Delivery Charge) + (Sum of items on Day 2 + Delivery Charge).
    *   If `SumA < 150`, add $D$. If `SumB < 150`, add $D$.
    *   Total = `SumA + SumB + (SumA < 150 ? D : 0) + (SumB < 150 ? D : 0)`.

2.  **With Coupon:**
    *   Cost = (Sum of items on Day 1) + (Sum of items on Day 2) + Coupon Price $C$.
    *   Note: The delivery charge is waived for both days regardless of the order total.
    *   Total = `SumA + SumB + C`.

**Decision Rule:**
Buy the coupon if `CostWithCoupon < CostWithoutCoupon`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the sums and costs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Cost without coupon: (SumA + D_charge1) + (SumB + D_charge2)
 * - Cost with coupon: SumA + SumB + C
 * 
 * Chef buys the coupon if: Cost_with_coupon < Cost_without_coupon
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
    long long deliveryDay1 = (sumA >= 150) ? 0 : D;
    long long deliveryDay2 = (sumB >= 150) ? 0 : D;
    long long costWithout = sumA + sumB + deliveryDay1 + deliveryDay2;
    
    // Total cost with coupon
    long long costWith = sumA + sumB + C;
    
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
```