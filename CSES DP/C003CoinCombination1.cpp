#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
const int MOD = 1e9 + 7;
int recom(int n, int sum, vector<int> &coins)
{

    if (sum == 0)
    {
        return 1;
    }

    if (dp[sum] != -1)
    {
        return dp[sum];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum - coins[i] >= 0)
        {
            ans = (ans + recom(n, sum - coins[i], coins)) % MOD;
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

    cout << recom(n, x, coins);

    return 0;
}