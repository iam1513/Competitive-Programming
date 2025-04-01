// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> dp;
// const int MOD = 1e9 + 7;
// int recom(int n, int sum, vector<int> &coins)
// {

//     if (sum == 0)
//     {
//         return 1;
//     }

//     if (dp[sum] != -1)
//     {
//         return dp[sum];
//     }

//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (sum - coins[i] >= 0)
//         {
//             ans = (ans + recom(n, sum - coins[i], coins)) % MOD;
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

ll f(ll n, ll x, vll &coins, vll &dp)
{
    if (x == 0)
    {
        return 1;
    }

    if (x < 0)
    {
        return 0;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (x - coins[i] >= 0)
        {
            ans = (ans + f(n, x - coins[i], coins, dp)) % MOD;
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

    vll coins(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vll dp(x + 1, 0);

    // ll ans = f(n, x, coins, dp);

    // cout << ans << endl;


    // TABULATION
    dp[0] = 1;

    for (ll i = 1; i <= x; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}