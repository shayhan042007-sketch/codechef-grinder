#include <iostream>
#include <algorithm>

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B;
    if (!(std::cin >> A >> B)) return 0;

    // Option 1: 3 blue pens = 3 * A
    // Option 2: 1 blue pen + 1 black pen = A + B
    int option1 = 3 * A;
    int option2 = A + B;

    // Output the minimum of the two options
    std::cout << std::min(option1, option2) << std::endl;

    return 0;
}