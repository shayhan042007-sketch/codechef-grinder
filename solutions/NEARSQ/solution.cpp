#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: NEARSQ
 * Logic: 
 * We need the largest square number A <= N.
 * If we take B = floor(sqrt(N)), then B*B is the largest square <= N.
 * Example: N = 10, sqrt(10) = 3.16, floor = 3, 3*3 = 9.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    int B = static_cast<int>(sqrt(N));
    cout << B * B << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}