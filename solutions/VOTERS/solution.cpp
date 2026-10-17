#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three sorted lists of voter IDs. We need to find IDs that appear
 * in at least two of the three lists.
 * 
 * Constraints: N1, N2, N3 <= 50,000. Total IDs <= 150,000.
 * Since the IDs are positive integers and the total count is manageable,
 * we can use a frequency map (std::map or std::unordered_map) or simply
 * collect all IDs into a single vector, sort them, and count occurrences.
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