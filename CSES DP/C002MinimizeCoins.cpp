// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> dp;
// int recom(int n, int sum, vector<int> &coins)
// {

//     if (sum == 0)
//     {
//         return 0;
//     }

//     if (dp[sum] != -1)
//     {
//         return dp[sum];
//     }

//     int ans = 1e9;
//     for (int i = 0; i < n; i++)
//     {
//         if (sum - coins[i] >= 0)
//         {
//             ans = min(ans, 1 + recom(n, sum - coins[i], coins));
//         }
//     }

//     return dp[sum] = ans;
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
//     dp.resize(x + 5, -1);

//     if (recom(n, x, coins) == 1e9)
//     {
//         cout << -1;
//         return 0;
//     }

//     cout << recom(n, x, coins);

//     return 0;
// }

#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>

#define pb push_back

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

using namespace std;

ll recom(ll n, ll x, vll &coins, vll &dp)
{
    if (x <= 0)
    {
        return 0;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    ll ans = 1e9;

    for (ll i = 0; i < n; i++)
    {
        if (x - coins[i] >= 0)
        {
            ans = min(ans, 1 + recom(n, x - coins[i], coins, dp));
        }
    }

    return dp[x] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;

    // vll dp(x + 1, -1);
    vll coins;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        coins.pb(a);
    }

    // ll ans = recom(n, x, coins, dp);

    // if (ans == 1e9)
    // {
    //     cout << -1 << endl;
    // }
    // else
    // {
    //     cout << ans << endl;
    // }

    // Tabulation
    vll dp(x + 1, 1e9);
    dp[0] = 0;

    for (ll i = 1; i <= x; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    if (dp[x] == 1e9)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[x] << endl;

    return 0;
}