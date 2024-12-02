#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define pb push_back

void calcUsingBcktrng(size_t idx, int wordsInc, vs& words, vi& sp, int& maxi, int m, int n) {
    maxi = max(maxi, wordsInc);

    // Base case
    if (idx >= words.size()) {
        return;
    }

    // Calculate size of the current word
    int wordSize = words[idx].length();

    // Try placing the word in existing lines
    for (size_t i = 0; i < sp.size(); ++i) { 
        // Calculate required space for the word
        int spReq = wordSize + (sp[i] > 0 ? 1 : 0); 
        if (spReq <= sp[i]) {
            int space = sp[i]; 
            sp[i] -= spReq; 
            
            calcUsingBcktrng(idx + 1, wordsInc + 1, words, sp, maxi, m, n);

            sp[i] = space; 
        }
    }

    
    if (sp.size() < static_cast<size_t>(n) && wordSize <= m) {
        sp.pb(m - wordSize); 
        calcUsingBcktrng(idx + 1, wordsInc + 1, words, sp, maxi, m, n);
        sp.pop_back(); // Backtracking
    }

    // Skip the current word and proceed
    calcUsingBcktrng(idx + 1, wordsInc, words, sp, maxi, m, n);
}

int omsJustifyWords(vs& words, int n, int m) {
    // Vector to keep track of remaining space in each line
    vi sp;

    int maxi = 0;

    // Call the recursive function
    calcUsingBcktrng(0, 0, words, sp, maxi, m, n);
    return maxi;
}

int main() {
    int k;
    cin >> k;

    vs words(k);
    for (int i = 0; i < k; ++i) cin >> words[i];

    int n, m;
    cin >> n >> m;

    cout << omsJustifyWords(words, n, m);

    return 0;
}
