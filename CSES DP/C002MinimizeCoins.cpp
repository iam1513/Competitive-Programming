#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
int recom(int n, int sum, vector<int> &coins)
{

    if (sum == 0)
    {
        return 0;
    }

    if (dp[sum] != -1)
    {
        return dp[sum];
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (sum - coins[i] >= 0)
        {
            ans = min(ans, 1 + recom(n, sum - coins[i], coins));
        }
    }

    return dp[sum] = ans;
}

int main()
{

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    dp.clear();
    dp.resize(x + 5, -1);

    if (recom(n, x, coins) == 1e9)
    {
        cout << -1;
        return 0;
    }

    cout << recom(n, x, coins);

    return 0;
}