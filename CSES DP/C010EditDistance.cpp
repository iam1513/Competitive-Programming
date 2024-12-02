#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> dp;

ll recom(string &s1, string &s2, int i, int j)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 1e9;

    if (s1[i] == s2[j])
    {
        ans = recom(s1, s2, i - 1, j - 1);
    }
    else
    {
        ans = 1 + min({recom(s1, s2, i - 1, j - 1), recom(s1, s2, i - 1, j), recom(s1, s2, i, j - 1)});
    }

    return dp[i][j] = ans;
}

int main()
{

    string s1, s2;
    cin >> s1;
    cin >> s2;

    dp.clear();
    dp.resize(s1.size() + 1, vector<ll>(s2.size() + 1, -1));

    ll ans = recom(s1, s2, s1.size() - 1, s2.size() - 1);
    cout << ans << endl;

    return 0;
}