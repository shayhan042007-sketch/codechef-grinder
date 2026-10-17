#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Buns required per day = 5 * X.
 * Number of days the buns last = N / (5 * X) (integer division).
 * Total survival days = (Days buns last) + D.
 * 
 * Constraints:
 * N < 500, X <= 10, D < 20.
 * The total number of buns consumed per day is 5 * X.
 * If 5 * X > N, the family cannot eat any buns, so they survive for D days.
 * The integer division N / (5 * X) correctly handles the case where N < 5 * X,
 * as it results in 0, leading to a total of 0 + D = D days.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, d;
        cin >> n >> x >> d;

        // Total buns required by the family of 5 per day
        long long daily_requirement = 5 * x;

        // Number of days the buns can sustain the family
        // If n < daily_requirement, this evaluates to 0
        long long days_with_food = n / daily_requirement;

        // Total survival time
        long long total_days = days_with_food + d;

        cout << total_days << "\n";
    }

    return 0;
}