#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time (T_tortoise) = ceil(L / V1)
 * Since L and V1 are integers, ceil(L / V1) can be calculated as (L + V1 - 1) / V1 using integer division.
 * 
 * Let 'w' be the integer wait time of the hare.
 * Hare time (T_hare) = w + ceil(L / V2)
 * Since L and V2 are integers, ceil(L / V2) = (L + V2 - 1) / V2.
 * 
 * The condition to win is: T_hare < T_tortoise
 * w + ceil(L / V2) < ceil(L / V1)
 * w < ceil(L / V1) - ceil(L / V2)
 * 
 * Since w must be an integer, the maximum w is ceil(L / V1) - ceil(L / V2) - 1.
 * If this value is less than 0, the hare cannot win, so output -1.
 */

void solve() {
    long long L, V1, V2;
    cin >> L >> V1 >> V2;

    // Calculate ceil(L / V1)
    long long t_tortoise = (L + V1 - 1) / V1;
    
    // Calculate ceil(L / V2)
    long long t_hare_run = (L + V2 - 1) / V2;

    // We need w + t_hare_run < t_tortoise
    // w < t_tortoise - t_hare_run
    long long max_w = t_tortoise - t_hare_run - 1;

    if (max_w < 0) {
        cout << -1 << "\n";
    } else {
        cout << max_w << "\n";
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