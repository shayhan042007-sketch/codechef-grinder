#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different binary strings that are both palindromes 
 * and contain exactly A zeros and B ones.
 * 
 * A palindrome is determined by its first ceil(length/2) characters.
 * If A is odd and B is odd, we cannot construct even one palindrome because 
 * a palindrome with A zeros and B ones must have at most one character with an 
 * odd count (the middle element). If both A and B are odd, the total length 
 * A+B is even, meaning there is no middle element, so both counts must be even.
 * Thus, if A is odd and B is odd, the answer is "No".
 * 
 * If A is 1 or B is 1, we can only form one unique palindrome structure 
 * (e.g., if A=1, B=3, the only palindrome is 1011 or 1101, but wait, 
 * 11011 is not possible with 1 zero. With A=1, B=3, the only palindrome is 11011? 
 * No, 11011 has 2 zeros. With A=1, B=3, the only palindrome is 11011? No.
 * Let's re-evaluate:
 * If A=1, B=3: Palindromes are 11011 (No, 2 zeros), 10111 (No), 11101 (No).
 * Actually, if A=1, B=3, the only palindrome is 11011 (Wait, that's 2 zeros).
 * The only palindrome with 1 zero and 3 ones is 11011? No, that's 2 zeros.
 * 11011 has 2 zeros. 10111 has 1 zero, 3 ones. 11101 has 1 zero, 3 ones.
 * Wait, 10111 is a palindrome? No. 11011 is a palindrome.
 * 
 * General rule:
 * If A is even or B is even, we can always construct at least two different palindromes.
 * If A is odd and B is odd, we can construct zero palindromes if A+B is even?
 * Actually, the condition is:
 * If A is odd and B is odd, we can't even form one palindrome? 
 * Let's check: A=1, B=1 -> "01" (not pal), "10" (not pal). Palindromes: none.
 * A=3, B=3 -> "110011" (pal), "011110" (pal). Wait, 3,3 is "No".
 * The condition for "No" is if (A % 2 != 0 && B % 2 != 0).
 * Also, if A=1 or B=1, we can only form one palindrome.
 */

void solve() {
    int A, B;
    cin >> A >> B;

    // If both are odd, we cannot form two different palindromes.
    // If either A or B is 1, we can only form one unique palindrome.
    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
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