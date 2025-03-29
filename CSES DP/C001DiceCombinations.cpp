// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 1e9 + 7; // Define the modulo value

// vector<int> dp;

// int om(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int ans = 0;

//     for (int i = 1; i <= 6; i++)
//     {
//         if (n - i >= 0)
//         {
//             ans = (ans + om(n - i)) % MOD; // Add and take modulo
//         }
//     }

//     return dp[n] = ans; // Store the result modulo MOD
// }

// int main()
// {
//     int n;
//     cin >> n;

//     if (n == 0)
//     {
//         cout << 0 << endl;
//         return 0;
//     }

//     dp.clear();
//     dp.resize(n + 5, -1);

//     cout << om(n) << endl;

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

ll recom(ll n, vector<ll> &dp)
{
    if (n == 0)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 0;

    if (n - 1 >= 0)
        ans = (ans + recom(n - 1, dp)) % MOD;
    if (n - 2 >= 0)
        ans = (ans + recom(n - 2, dp)) % MOD;
    if (n - 3 >= 0)
        ans = (ans + recom(n - 3, dp)) % MOD;
    if (n - 4 >= 0)
        ans = (ans + recom(n - 4, dp)) % MOD;
    if (n - 5 >= 0)
        ans = (ans + recom(n - 5, dp)) % MOD;
    if (n - 6 >= 0)
        ans = (ans + recom(n - 6, dp)) % MOD;

    return dp[n] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> dp(n + 5, 0);
    // cout << recom(n, dp) << endl;

    // Tabulation

    dp[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}