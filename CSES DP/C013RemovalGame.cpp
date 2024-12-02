#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> dp;

ll recom(ll n, vector<ll> &nums, ll i, ll j)
{
    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != LLONG_MIN)
    {
        return dp[i][j];
    }

    return dp[i][j] = max(nums[i] + min(recom(n, nums, i + 2, j), recom(n, nums, i + 1, j - 1)), nums[j] + min(recom(n, nums, i + 1, j - 1), recom(n, nums, i, j - 2)));
}

int main()
{

    ll n;
    cin >> n;

    vector<ll> nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    dp.clear();
    dp.resize(n, vector<ll>(n, LLONG_MIN));

    ll ans = recom(n, nums, 0, n - 1);

    cout << ans << endl;

    return 0;
}
