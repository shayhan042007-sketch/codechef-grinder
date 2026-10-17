#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 2N total players, X of whom are rated.
 * We want to minimize the number of rated players paired with other rated players.
 * 
 * Let R = X (rated players)
 * Let U = 2N - X (unrated players)
 * 
 * We want to maximize the number of (Rated, Unrated) pairs.
 * Each (Rated, Unrated) pair uses 1 rated player and 1 unrated player.
 * The maximum number of such pairs we can form is min(R, U).
 * 
 * After forming min(R, U) pairs, we have used min(R, U) rated players.
 * The remaining rated players are R - min(R, U).
 * Since all unrated players are already paired (or there were no unrated players to begin with),
 * the remaining rated players must be paired with each other.
 * 
 * Each pair of (Rated, Rated) consists of 2 rated players.
 * So the number of rated players with rated opponents is simply the number of 
 * remaining rated players, which is R - min(R, U).
 * 
 * If R <= U:
 *   min(R, U) = R
 *   Result = R - R = 0
 * If R > U:
 *   min(R, U) = U
 *   Result = R - U
 * 
 * This can be simplified to: max(0, R - U)
 * Substituting U = 2N - X:
 * Result = max(0, X - (2N - X)) = max(0, 2X - 2N)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        long long unrated = 2 * n - x;
        long long result = 0;
        
        if (x > unrated) {
            result = x - unrated;
        } else {
            result = 0;
        }
        
        cout << result << "\n";
    }
    
    return 0;
}