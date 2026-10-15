#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two strings A and B of length N, consisting only of 'a' and 'b'.
 * We can shuffle A and B independently. We want to check if there exists a 
 * permutation of A (let's call it A') and a permutation of B (let's call it B')
 * such that A'[i] != B'[i] for all i.
 * 
 * Let countA_a be the number of 'a's in A, countA_b be the number of 'b's in A.
 * Let countB_a be the number of 'a's in B, countB_b be the number of 'b's in B.
 * 
 * To satisfy A'[i] != B'[i], if A'[i] is 'a', B'[i] must be 'b'.
 * If A'[i] is 'b', B'[i] must be 'a'.
 * 
 * This means:
 * 1. The number of 'a's in A must equal the number of 'b's in B.
 *    countA_a == countB_b
 * 2. The number of 'b's in A must equal the number of 'a's in B.
 *    countA_b == countB_a
 * 
 * Note that since countA_a + countA_b = N and countB_a + countB_b = N,
 * these two conditions are actually equivalent. If countA_a == countB_b,
 * then N - countA_a = N - countB_b => countA_b = countB_a.
 * 
 * So the condition is simply: countA_a == countB_b.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA_a = 0;
    for (char c : A) {
        if (c == 'a') countA_a++;
    }

    int countB_b = 0;
    for (char c : B) {
        if (c == 'b') countB_b++;
    }

    if (countA_a == countB_b) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}