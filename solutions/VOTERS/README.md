# [Discrepancies in the Voters List (VOTERS)](https://www.codechef.com/problems/VOTERS)

- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary
We are provided with three separate lists of voter IDs, each already sorted in ascending order. The goal is to identify all voter IDs that appear in at least two of the three lists. The final output must list these IDs in ascending order, preceded by the total count of such IDs.

## Intuition & Mathematical Observation
Since the problem asks for IDs that appear in at least two lists, we are essentially looking for elements with a frequency count $\ge 2$ across the combined dataset.

1. **Data Aggregation**: We can read all IDs from the three lists into a single collection.
2. **Frequency Counting**: Using a `std::map<int, int>` is an ideal approach here. A map stores elements as key-value pairs where the key is the voter ID and the value is its frequency.
3. **Sorting**: A `std::map` in C++ automatically keeps its keys sorted in ascending order. This satisfies the problem requirement to output the IDs in sorted order without needing an explicit sorting step after processing.
4. **Filtering**: After populating the map, we iterate through it and collect all keys whose associated value (frequency) is 2 or 3.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$, where $N = N_1 + N_2 + N_3$. Inserting $N$ elements into a `std::map` takes $O(N \log K)$ time, where $K$ is the number of unique IDs. In the worst case, $K \approx N$, leading to $O(N \log N)$. Given $N \le 150,000$, this comfortably fits within the time limit.
- **Space Complexity**: $O(N)$, as we store all unique voter IDs in the map and the resulting IDs in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three sorted lists of voter IDs. We need to find IDs that appear
 * in at least two of the three lists.
 * 
 * Constraints: N1, N2, N3 <= 50,000. Total IDs <= 150,000.
 * Since the IDs are positive integers and the total count is manageable,
 * we can use a frequency map (std::map) to count occurrences.
 * 
 * Given the constraints and the nature of the problem, a frequency map is 
 * efficient enough. Since we need the output in ascending order, a std::map
 * is perfect as it keeps keys sorted.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    // Use a map to store the frequency of each ID.
    // Map keys are automatically sorted.
    map<int, int> frequency_map;

    int total_elements = n1 + n2 + n3;
    for (int i = 0; i < total_elements; ++i) {
        int id;
        cin >> id;
        frequency_map[id]++;
    }

    // Collect IDs that appear in at least 2 lists
    vector<int> result;
    for (auto const& [id, count] : frequency_map) {
        if (count >= 2) {
            result.push_back(id);
        }
    }

    // Output the count of such IDs
    cout << result.size() << "\n";
    
    // Output the IDs in ascending order
    for (int id : result) {
        cout << id << "\n";
    }

    return 0;
}
```