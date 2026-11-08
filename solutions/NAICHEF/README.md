# [Naive Chef (NAICHEF)](https://www.codechef.com/problems/NAICHEF)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a die with $N$ faces, where each face has a specific value. We toss this die twice. We need to calculate the probability that the first toss results in the value $A$ and the second toss results in the value $B$.

## Intuition & Mathematical Observation
Since the die is tossed twice independently, the outcome of the first toss does not affect the outcome of the second toss.

1. **Probability of a single event**: The probability of rolling a specific value $v$ in one toss is given by:
   $$P(v) = \frac{\text{count of faces with value } v}{N}$$
2. **Combined Probability**: Because the two tosses are independent, the probability of both events occurring (getting $A$ on the first toss AND $B$ on the second toss) is the product of their individual probabilities:
   $$P(\text{Win}) = P(A) \times P(B)$$
   $$P(\text{Win}) = \left( \frac{\text{count of } A}{N} \right) \times \left( \frac{\text{count of } B}{N} \right)$$

By counting the occurrences of $A$ and $B$ in the input array in a single pass, we can compute the result efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of faces on the die. We iterate through the list of faces exactly once to count the occurrences of $A$ and $B$.
- **Space Complexity**: $O(N)$ to store the face values (or $O(1)$ if we process the input values on the fly without storing them in a vector).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The die has N faces. Each face has a value x_i.
 * The probability of getting a specific value 'v' in one toss is:
 * P(v) = (count of faces with value v) / N
 * 
 * Since the two tosses are independent, the probability of getting A on the first
 * toss and B on the second toss is:
 * P(Win) = P(A) * P(B)
 * P(Win) = (count of A * count of B) / (N * N)
 */

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;
    
    long long countA = 0;
    long long countB = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == A) {
            countA++;
        }
        if (val == B) {
            countB++;
        }
    }
    
    // Calculate probability
    // Use double for precision as required by the problem
    double probA = (double)countA / N;
    double probB = (double)countB / N;
    double result = probA * probB;
    
    cout << fixed << setprecision(10) << result << "\n";
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