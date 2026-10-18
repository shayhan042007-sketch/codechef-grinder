#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at city X and jumps by K each day in a circular arrangement of N cities.
 * The sequence of cities visited is: X, (X+K)%N, (X+2K)%N, ...
 * This is equivalent to checking if there exists an integer 'm' such that:
 * (X + m * K) % N == Y
 * This is a linear congruence equation: m * K ≡ (Y - X) (mod N).
 * 
 * Given the constraints N <= 1000, we can simply simulate the process.
 * Since there are only N cities, if the virus visits a city it has already visited
 * without reaching Y, it will never reach Y.
 */

void solve() {
    int N, K, X, Y;
    if (!(cin >> N >> K >> X >> Y)) return;

    // visited array to keep track of infected cities
    vector<bool> visited(N, false);
    
    int current = X;
    bool reached = false;
    
    // Simulate the jumps
    // In the worst case, we visit at most N cities.
    for (int i = 0; i < N; ++i) {
        if (current == Y) {
            reached = true;
            break;
        }
        
        // If we hit a city already visited, we are in a cycle
        if (visited[current]) {
            break;
        }
        
        visited[current] = true;
        current = (current + K) % N;
    }
    
    if (reached) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}