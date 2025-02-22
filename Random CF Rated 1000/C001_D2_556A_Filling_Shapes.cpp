// #include <bits/stdc++.h>

// #define ll long long
// #define pll pair<ll, ll>
// #define vll vector<ll>
// #define mll map<ll, ll>
// #define sl set<ll>
// #define sc set<char>

// #define pb push_back

// #define MOD 1000000007
// #define PI 3.1415926535897932384626433832795

// ll gcd(ll a, ll b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// bool prime(ll a)
// {
//     if (a == 1)
//         return 0;
//     for (int i = 2; i <= round(sqrt(a)); ++i)
//         if (a % i == 0)
//             return 0;
//     return 1;
// }

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     ll n;
//     cin >> n;

//     if (n % 2 == 1)
//     {
//         cout << 0 << endl;
//         return 0;
//     }
//     ll size = n / 2 + 1;
//     vll nums(n / 2 + 1, 0);
//     nums[1] = 2;

//     for (ll i = 2; i <= size; i++)
//     {
//         ll sum = 0;
//         for (ll j = 1; j < i; j++)
//         {
//             sum += nums[j];
//         }
//         nums[i] = sum;
//     }

//     cout << nums[size] << endl;

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

ll f(ll idx, vll &dp, ll n)
{
    if (idx < 2)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    return dp[idx] = 2 * f(idx - 2, dp, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    vll dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 2;

    ll ans = f(n, dp, n);
    cout << ans << endl;
    return 0;
}