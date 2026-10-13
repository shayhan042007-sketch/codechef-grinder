#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1 allows us to convert any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter 'X' as its lowercase 
 *    counterpart 'x' for the purpose of counting potential occurrences.
 * 2. Operation 2 allows us to pick one lowercase letter and merge all its occurrences 
 *    into another lowercase letter.
 * 3. To maximize the score, we should:
 *    a. Convert all uppercase letters to lowercase.
 *    b. Count the frequency of each lowercase letter.
 *    c. Choose one letter 'x' and merge it with another letter 'y' to maximize the count.
 *       Wait, the operation says: "choose exactly one lowercase letter and convert 
 *       all of its occurrences into another lowercase letter."
 *       This means if we have counts for 'a', 'b', 'c', ..., we can pick 'a' and 
 *       add its count to 'b'. The new count for 'b' becomes count('b') + count('a').
 *       Since we want to maximize the score, we should pick the letter with the 
 *       highest frequency and add the frequency of any other letter to it.
 *       Actually, we can pick any letter 'x' and merge it into 'y'. To maximize, 
 *       we should pick the letter with the second-highest frequency and merge it 
 *       into the letter with the highest frequency.
 * 
 * Complexity:
 * Time: O(N) per test case.
 * Space: O(1) (since the alphabet size is fixed at 26).
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> freq(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        } else {
            freq[c - 'a']++;
        }
    }

    // Find the two largest frequencies
    int max1 = 0, max2 = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > max1) {
            max2 = max1;
            max1 = freq[i];
        } else if (freq[i] > max2) {
            max2 = freq[i];
        }
    }

    // The result is the sum of the two largest frequencies
    cout << max1 + max2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}