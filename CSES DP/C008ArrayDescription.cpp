#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

vector<ll> arr;
vector<vector<ll>> memo;
ll n, m;

ll solve(int i, int prev)
{
    if (prev < 1 || prev > m)
        return 0;

    if (i == 0)
        return (arr[i] == 0 || arr[i] == prev) ? 1 : 0;

    if (memo[i][prev] != -1)
        return memo[i][prev];

    if (arr[i] != 0 && arr[i] != prev)
        return memo[i][prev] = 0;

    return memo[i][prev] = ((solve(i - 1, prev - 1) % MOD + solve(i - 1, prev) % MOD) % MOD +
                            solve(i - 1, prev + 1)) %
                           MOD;
}

int main()
{
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memo.assign(n, vector<ll>(m + 1, -1));
    ll result = 0;
    for (int j = 1; j <= m; j++)
        result = (result + solve(n - 1, j)) % MOD;
    cout << result << endl;
    return 0;
}

/*#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

vector<ll> arr;
vector<vector<ll>> dp;
ll n, m;

int main()
{
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp.clear();
    dp.resize(n, vector<ll>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        // Base case
        if (i == 0)
        {
            if (arr[i] != 0)
            {
                dp[i][arr[i]] = 1;
            }
            else
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = 1;
                }
            }
            continue;
        }

        // Transition
        if (arr[i] != 0)
        {
            dp[i][arr[i]] = ((arr[i] > 1 ? dp[i - 1][arr[i] - 1] : 0) + dp[i - 1][arr[i]] +
                             (arr[i] < m ? dp[i - 1][arr[i] + 1] : 0)) % MOD;
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = ((j > 1 ? dp[i - 1][j - 1] : 0) + dp[i - 1][j] +
                            (j < m ? dp[i - 1][j + 1] : 0)) % MOD;
            }
        }
    }

    // Sum over all possible states in the last row
    ll result = 0;
    for (int j = 1; j <= m; j++)
    {
        result = (result + dp[n - 1][j]) % MOD;
    }

    cout << result << endl;

    return 0;
}
*/