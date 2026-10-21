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