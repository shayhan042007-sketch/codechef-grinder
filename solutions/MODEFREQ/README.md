# [Mode of Frequencies (MODEFREQ)](https://www.codechef.com/problems/MODEFREQ)

- **Difficulty Rating**: 1234
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to determine which frequency occurs most often among the elements. If there is a tie (i.e., multiple frequencies appear the same maximum number of times), we must output the smallest frequency value among those tied.

## Intuition & Mathematical Observation
1. **Frequency Counting**: First, we count how many times each number appears in the input array. A `std::map<int, int>` or a frequency array (since $A_i \le 10000$) is suitable for this.
2. **Frequency of Frequencies**: Once we have the counts of each number, we need to count how many numbers share the same frequency. For example, if the number `5` appears 3 times and the number `7` appears 3 times, the frequency `3` has an occurrence count of `2`.
3. **Finding the Mode**: We iterate through the "frequency of frequencies" map. We track the maximum occurrence count found so far.
4. **Tie-Breaking**: Since we need the smallest frequency in case of a tie, using a `std::map` to store the "frequency of frequencies" is advantageous because it automatically keeps the keys (the frequencies) sorted in ascending order. By iterating through the map linearly, we only update our result if we find a strictly greater occurrence count, naturally preserving the smallest frequency for any ties.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the implementation. Using `std::map` results in $O(N \log N)$ due to insertion and lookup overhead. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the frequency counts of the input elements and the subsequent frequency-of-frequency counts.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * 1. Count the frequency of each number present in the input array.
 * 2. Count how many numbers share the same frequency (freq_of_freq).
 * 3. Find the frequency that appears most often in the freq_of_freq map.
 * 4. Tie-break by choosing the smallest frequency value.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Using a map to handle arbitrary values of A_i safely, 
    // though an array of size 10001 is sufficient per constraints.
    map<int, int> count_map;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        count_map[val]++;
    }
    
    // Map to store how many numbers have a specific frequency
    // freq_of_freq[f] = how many numbers appear exactly f times
    map<int, int> freq_of_freq;
    for (auto const& [val, freq] : count_map) {
        freq_of_freq[freq]++;
    }
    
    int max_occurrence = -1;
    int result_freq = -1;
    
    // Iterate through the map. Since std::map is sorted by key (frequency),
    // we naturally encounter frequencies in increasing order.
    for (auto const& [freq, count] : freq_of_freq) {
        if (count > max_occurrence) {
            max_occurrence = count;
            result_freq = freq;
        }
        // No need for explicit tie-breaking logic for the smallest frequency
        // because the map iteration is already in ascending order of 'freq'.
    }
    
    cout << result_freq << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```