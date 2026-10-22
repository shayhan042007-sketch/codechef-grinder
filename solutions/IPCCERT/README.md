# [Chef and IPC Certificates (IPCCERT)](https://www.codechef.com/problems/IPCCERT)

- **Difficulty Rating**: 922
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef is organizing an IPC certification program. To receive a certificate, a student must meet two specific criteria:
1. The total time spent watching lecture videos must be at least $M$ minutes.
2. The number of questions asked by the student during the sessions must be no more than 10.

Given $N$ students, each having watched $K$ videos and asked $Q$ questions, we need to count how many students are eligible for the certificate.

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. For each student:
1. We are given $K$ integers representing the duration of each video watched. We simply need to calculate the sum of these $K$ integers.
2. We are given an integer $Q$ representing the number of questions asked.
3. A student is eligible if `sum_of_times >= M` AND `Q <= 10`.

Since we only need to track the count of eligible students, we do not need to store the data for all students. We can process each student one by one, maintaining a running count, which keeps our space complexity minimal.

## Complexity Analysis
- **Time Complexity**: $O(N \times K)$, where $N$ is the number of students and $K$ is the number of videos per student. We iterate through every video duration for every student exactly once.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current student's data and the running count, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

/**
 * Problem: IPCCERT
 * Complexity Analysis:
 * Time Complexity: O(N * K)
 * Space Complexity: O(1)
 * 
 * The logic remains O(N * K). By ensuring we use fast I/O and minimal 
 * memory allocation, we ensure the solution passes within the time limit.
 */

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    long long M;

    if (!(cin >> N >> M >> K)) return 0;

    int eligible_count = 0;

    for (int i = 0; i < N; ++i) {
        long long total_time = 0;
        for (int j = 0; j < K; ++j) {
            int t;
            cin >> t;
            total_time += t;
        }

        int Q;
        cin >> Q;

        // Criteria:
        // 1. Total time watched >= M
        // 2. Questions asked <= 10
        if (total_time >= M && Q <= 10) {
            eligible_count++;
        }
    }

    cout << eligible_count << "\n";

    return 0;
}
```