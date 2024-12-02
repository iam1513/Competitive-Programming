// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// vector<vector<ll>> dp;

// ll recom(ll a, ll b)
// {
//     if (a == b)
//     {
//         return 0;
//     }

//     if (dp[a][b] != -1)
//     {
//         return dp[a][b];
//     }

//     ll ans = LLONG_MAX;

//     for (int i = 1; i < a; i++)
//     {
//         ans = min(ans, 1 + recom(i, b) + recom(a - i, b));
//     }

//     for (int j = 1; j < b; j++)
//     {
//         ans = min(ans, 1 + recom(a, j) + recom(a, b - j));
//     }

//     return dp[a][b] = ans;
// }

// int main()
// {

//     ll a, b;
//     cin >> a >> b;

//     dp.clear();
//     dp.resize(a + 1, vector<ll>(b + 1, -1));

//     ll ans = recom(a, b);

//     cout << ans << endl;

//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll a, b;
    cin >> a >> b;

    // Create a DP table
    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, LLONG_MAX));

    // Base cases
    for (ll i = 1; i <= a; i++)
    {
        for (ll j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0; // Already a square
            }
            else
            {
                // Cut horizontally
                for (ll k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                // Cut vertically
                for (ll k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}
