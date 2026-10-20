#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length N.
 * L(V) = S implies V[1...N-1] + V[0] = S[0...N-1]
 * This means V[i] = S[(i+1)%N]
 * 
 * R(V) = S implies V[N-1] + V[0...N-2] = S[0...N-1]
 * This means V[i] = S[(i-1+N)%N]
 * 
 * For a valid V to exist, both conditions must be satisfied by the same V.
 * Specifically, L(V) = S means V is R(S).
 * R(V) = S means V is L(S).
 * So we need to check if R(S) == L(S).
 * 
 * R(S) is shifting S right by 1: S[N-1] + S[0...N-2]
 * L(S) is shifting S left by 1: S[1...N-1] + S[0]
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Construct L(S)
    string left_shifted = s.substr(1) + s[0];
    
    // Construct R(S)
    string right_shifted = s.back() + s.substr(0, n - 1);
    
    if (left_shifted == right_shifted) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}