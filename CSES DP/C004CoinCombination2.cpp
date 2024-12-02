// #include <iostream>
// #include <vector>
// using namespace std;
// vector<vector<int>> dp;
// const int MOD = 1e9 + 7;
// int recom(int n, int sum, vector<int> &coins, int j)
// {

//     if (sum == 0)
//     {
//         return 1;
//     }

//     if (dp[sum][j] != -1)
//     {
//         return dp[sum][j];
//     }

//     int ans = 0;
//     for (int i = j; i < n; i++)
//     {
//         if (sum - coins[i] >= 0)
//         {
//             ans = (ans + recom(n, sum - coins[i], coins, i)) % MOD;
//         }
//     }

//     return dp[sum][j] = ans;
// }

// int main()
// {

//     int n, x;
//     cin >> n >> x;

//     vector<int> coins(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> coins[i];
//     }

//     dp.clear();
//     dp.resize(x + 5, vector<int>(n + 5, -1));

//     cout << recom(n, x, coins, 0);

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= x; j++)
        {
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
        }
    }

    cout << dp[x] << endl;

    return 0;
}
