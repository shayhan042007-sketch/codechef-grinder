#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A cab can hold at most 4 people.
 * Cost for X people in one cab = max(200, 100 * X).
 * 
 * If we put 1 person: cost = max(200, 100) = 200
 * If we put 2 people: cost = max(200, 200) = 200
 * If we put 3 people: cost = max(200, 300) = 300
 * If we put 4 people: cost = max(200, 400) = 400
 * 
 * To minimize cost, we want to maximize the number of people per cab 
 * while keeping the cost per person low.
 * 
 * Let's analyze the cost per person:
 * 1 person: 200/1 = 200
 * 2 people: 200/2 = 100
 * 3 people: 300/3 = 100
 * 4 people: 400/4 = 100
 * 
 * Since the cost per person is 100 for 2, 3, or 4 people, and 200 for 1 person,
 * we should always try to fill cabs with 2, 3, or 4 people.
 * Specifically, filling a cab with 4 people is always efficient.
 * If we have N people, we can use (N / 4) cabs of 4 people.
 * If there is a remainder R:
 * If R = 1: We have a group of 1. If we have other cabs, we can move one person 
 * from a full cab to make two groups of 2 (cost 200+200=400) instead of 400+200=600.
 * Actually, simply put:
 * Each cab of 4 costs 400.
 * Each cab of 3 costs 300.
 * Each cab of 2 costs 200.
 * Each cab of 1 costs 200.
 * 
 * The most efficient way is to use as many 4-person cabs as possible.
 * If N % 4 == 0: Cost = (N/4) * 400
 * If N % 4 == 1: (N/4 - 1) cabs of 4, and 2 cabs of 2 (or 1 cab of 3 and 1 of 2). 
 * Actually, 400 * (N/4 - 1) + 200 + 200 = 400 * (N/4)
 * If N % 4 == 2: (N/4) cabs of 4, and 1 cab of 2 (cost 200).
 * If N % 4 == 3: (N/4) cabs of 4, and 1 cab of 3 (cost 300).
 */

void solve() {
    int N;
    cin >> N;
    
    int cost = 0;
    int full_cabs = N / 4;
    int remainder = N % 4;
    
    cost += full_cabs * 400;
    
    if (remainder == 1) {
        if (full_cabs > 0) {
            // Take one person from a full cab: 400 -> 300, and add a cab of 2: 200
            // Total: (full_cabs - 1) * 400 + 300 + 200 = full_cabs * 400 + 100
            // Wait, simpler: 400 * full_cabs + 100 is not possible.
            // If N=5: 1 cab of 4 (400) + 1 cab of 1 (200) = 600.
            // Better: 1 cab of 3 (300) + 1 cab of 2 (200) = 500.
            cost = (full_cabs - 1) * 400 + 500;
        } else {
            cost = 200;
        }
    } else if (remainder == 2) {
        cost += 200;
    } else if (remainder == 3) {
        cost += 300;
    }
    
    cout << cost << "\n";
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