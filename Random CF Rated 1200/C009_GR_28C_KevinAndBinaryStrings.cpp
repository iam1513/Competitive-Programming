#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Function to convert a binary string to a number
ll binaryToNumber(const string& s) {
    ll num = 0;
    for (char ch : s) {
        num = (num << 1) + (ch - '0');
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        ll max_xor = 0;
        int l2_ans = 1, r2_ans = 1;

        // Fix the first substring as the entire string
        string substr1 = s;
        ll num1 = binaryToNumber(substr1);

        // Iterate over all possible substrings for the second substring
        for (int l2 = 0; l2 < n; l2++) {
            for (int r2 = l2; r2 < n; r2++) {
                string substr2 = s.substr(l2, r2 - l2 + 1);
                ll num2 = binaryToNumber(substr2);

                // Compute XOR
                ll current_xor = num1 ^ num2;

                // Update maximum XOR and indices
                if (current_xor > max_xor) {
                    max_xor = current_xor;
                    l2_ans = l2 + 1; // Convert to 1-based indexing
                    r2_ans = r2 + 1;
                }
            }
        }

        cout << 1 << " " << n << " " << l2_ans << " " << r2_ans << "\n";
    }

    return 0;
}