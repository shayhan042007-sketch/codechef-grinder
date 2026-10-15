#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N rows, each with 2 seats. Total seats = 2N.
 * People enter one by one.
 * Strategy:
 * 1. People prefer to sit in an empty row.
 * 2. If no empty row is available, they sit next to someone.
 * 
 * Let R be the number of rows.
 * If K <= N:
 * Each person takes one row. No one sits next to anyone. Result = 0.
 * 
 * If K > N:
 * The first N people will each take one row (one seat per row).
 * After N people, all N rows have exactly 1 person.
 * The remaining (K - N) people must sit in a row that already has 1 person.
 * When a person sits in a row that already has 1 person, both the person 
 * already there and the new person are now "sitting next to somebody".
 * 
 * So, for the (K - N) people who arrive after the rows are filled:
 * Each of these (K - N) people will sit next to the person already in that row.
 * This makes 2 people per row "sitting next to somebody".
 * Total = (K - N) * 2.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k <= n) {
            cout << 0 << "\n";
        } else {
            // The first n people occupy one seat in each of the n rows.
            // The remaining (k - n) people sit in rows that already have 1 person.
            // Each of these (k - n) people joins an existing person, 
            // meaning 2 people per join are now sitting next to someone.
            cout << (k - n) * 2 << "\n";
        }
    }

    return 0;
}