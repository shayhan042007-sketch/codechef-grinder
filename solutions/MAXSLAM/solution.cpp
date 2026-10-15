#include <iostream>

/**
 * Problem Analysis:
 * Chef needs at least 25 total wins.
 * Current wins = X.
 * Wins needed = 25 - X.
 * Each year, Chef wins 4 Grand Slams.
 * Let Y be the number of years.
 * We need 4 * Y >= 25 - X.
 * Therefore, Y = ceil((25 - X) / 4.0).
 * Using integer arithmetic, this is equivalent to (25 - X + 3) / 4.
 * 
 * Note: The problem input format specifies a single integer X, 
 * not a number of test cases T.
 */

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long X;
    if (!(std::cin >> X)) return 0;
    
    long long needed = 25 - X;
    
    // Since constraints are 0 <= X <= 24, needed is always > 0.
    // Ceiling division of (needed / 4) is (needed + 4 - 1) / 4
    long long years = (needed + 3) / 4;
    
    std::cout << years << std::endl;
    
    return 0;
}