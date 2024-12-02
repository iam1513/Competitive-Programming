// #include <iostream>
// #include <vector>
// using namespace std;

// vector<vector<int>> dp;

// int maxPages(int idx, int sum, vector<int> &prices, vector<int> &pages)
// {
//     if (sum == 0 || idx == prices.size())
//         return 0;

//     if (dp[idx][sum] != -1)
//         return dp[idx][sum];

//     int notTaken = maxPages(idx + 1, sum, prices, pages);
//     int taken = 0;
//     if (sum >= prices[idx])
//         taken = pages[idx] + maxPages(idx + 1, sum - prices[idx], prices, pages);

//     return dp[idx][sum] = max(taken, notTaken);
// }

// int main()
// {
//     int n, x;
//     cin >> n >> x;

//     vector<int> prices(n), pages(n);

//     for (int i = 0; i < n; i++)
//         cin >> prices[i];

//     for (int i = 0; i < n; i++)
//         cin >> pages[i];

//     dp.assign(n, vector<int>(x + 1, -1));
//     cout << maxPages(0, x, prices, pages) << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= prices[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}
