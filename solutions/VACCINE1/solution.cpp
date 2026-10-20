#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two companies starting production on different days D1 and D2.
 * Company A produces V1 vaccines/day starting from day D1.
 * Company B produces V2 vaccines/day starting from day D2.
 * We need to find the smallest day 'd' such that the total vaccines produced >= P.
 * 
 * Since the constraints are small (D, V <= 100, P <= 1000), we can simulate 
 * day by day or use a simple loop. Given the constraints, a simple loop 
 * up to 2000 days is more than sufficient.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    int total_vaccines = 0;
    int day = 0;

    // Simulate day by day until total_vaccines >= P
    while (total_vaccines < P) {
        day++;
        
        // Check if Company A is producing on this day
        if (day >= D1) {
            total_vaccines += V1;
        }
        
        // Check if Company B is producing on this day
        if (day >= D2) {
            total_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}