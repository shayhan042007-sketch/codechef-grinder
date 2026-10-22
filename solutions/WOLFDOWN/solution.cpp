#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * The simulation approach is valid given N <= 100.
 * The previous TLE was likely due to the simulation logic not terminating 
 * correctly or being inefficient.
 * We can simulate the process for at most N seconds.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> wolf_pos;
    vector<bool> is_bird(N, false);
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            wolf_pos.push_back(i);
        } else {
            is_bird[i] = true;
        }
    }

    // Simulation:
    // A bird is eaten if a wolf is at pos x and bird is at x+1.
    // We simulate for N seconds because a wolf can move at most N times.
    for (int t = 0; t < N; ++t) {
        vector<bool> eaten(N, false);
        vector<int> next_wolf_pos = wolf_pos;
        
        // Identify which birds get eaten this second
        vector<bool> will_be_eaten(N, false);
        for (int i = 0; i < wolf_pos.size(); ++i) {
            int p = wolf_pos[i];
            if (p + 1 < N && is_bird[p + 1]) {
                will_be_eaten[p + 1] = true;
            }
        }

        // Update state
        for (int i = 0; i < wolf_pos.size(); ++i) {
            int p = wolf_pos[i];
            if (p + 1 < N && will_be_eaten[p + 1]) {
                is_bird[p + 1] = false;
                next_wolf_pos[i] = p + 1;
            }
        }
        wolf_pos = next_wolf_pos;
    }

    int safe_birds = 0;
    for (int i = 0; i < N; ++i) {
        if (is_bird[i]) {
            safe_birds++;
        }
    }
    cout << safe_birds << "\n";
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