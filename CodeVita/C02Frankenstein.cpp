#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <climits>
#include <algorithm>

using namespace std;

// DP 
unordered_map<string, int> dp;

int OmsFunMinOrbs( string &tp,unordered_map<string, vector<vector<string>>> &rb) {

    // If we are at end , return 0. This is our base case
    if (rb.find(tp) == rb.end()) {
        return 0;
    }

    // If we have ans already computed in dp, return the ans
    if (dp.find(tp) != dp.end()) {
        return dp[tp];
    }

    // Answer initialised with maximum value
    int ans_count = INT_MAX;

    // Find answer recursively
    for (auto &st : rb[tp]) {
        int orbs = st.size() - 1; 
        for (auto &ing : st) {
            orbs += OmsFunMinOrbs(ing,rb);
        }

        ans_count = min(ans_count, orbs);
    }

    
    return dp[tp] = ans_count;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    // Map to store string before = and then a vector, to store every thing after that
    unordered_map<string, vector<vector<string>>> rb;

    // Input recipes.
    for (int i = 0; i < n; i++) {
        string st;
        cin>>st;

        // Find where = is present to split the input
        size_t pos = st.find('=');

        // ings for ingredients
        string ings = st.substr(pos + 1);

        // pn for potion
        string pn = st.substr(0, pos);

        stringstream ss(ings);
        // ing for a single incredient
        string ing;
        vector<string> ingredients;

// Extract every ingredient when we pass = sign and since we have + in between , we have to split accordingly
        while (getline(ss, ing, '+')) {
            ingredients.push_back(ing);
        }

        rb[pn].push_back(ingredients);
    }

    // Take target portion as Input
    string tp;
    cin>>tp;

    // Call the function for calculating and print ans
    cout<<OmsFunMinOrbs(tp,rb);

    return 0;
}
