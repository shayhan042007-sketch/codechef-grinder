#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A "good" array has alternating parities (Odd, Even, Odd, Even... or Even, Odd, Even, Odd...).
 * To maximize the size of a subset that can be rearranged into a good array, we need to 
 * count the number of odd integers (O) and even integers (E) in the input array.
 * 
 * In an alternating sequence:
 * - If we have O odds and E evens:
 *   - If O == E, we can use all O + E elements (e.g., O, E, O, E...).
 *   - If O != E, the maximum length is limited by the smaller count. 
 *     Specifically, if we have more of one type, we can place them such that 
 *     the sequence is (Majority, Minority, Majority, Minority, Majority).
 *     The maximum length is 2 * min(O, E) + 1.
 * 
 * Therefore, the answer is:
 * - If O == E: O + E
 * - If O != E: 2 * min(O, E) + 1
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count == even_count) {
        cout << odd_count + even_count << "\n";
    } else {
        cout << 2 * min(odd_count, even_count) + 1 << "\n";
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