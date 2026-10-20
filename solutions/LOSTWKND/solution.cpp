#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef has 5 weekdays. For each day i, he has A_i hours of work to do at the office.
 * 1 hour of office work = P hours of home work.
 * Total work required in home hours = (A_1 + A_2 + A_3 + A_4 + A_5) * P.
 * Total available hours in 5 weekdays = 5 * 24 = 120 hours.
 * 
 * If the total work required exceeds 120 hours, Chef must work on the weekend.
 * Otherwise, he can finish within the 5 weekdays.
 */

void solve() {
    long long total_work_needed = 0;
    long long val;
    
    // Read the 5 days of work
    for (int i = 0; i < 5; ++i) {
        cin >> val;
        total_work_needed += val;
    }
    
    // Read P
    long long P;
    cin >> P;
    
    // Calculate total work in home hours
    total_work_needed *= P;
    
    // Total hours available in 5 weekdays (5 days * 24 hours/day)
    const long long total_hours_available = 120;
    
    // If total work needed is greater than available, he must work on weekends
    if (total_work_needed > total_hours_available) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}