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

//     ll n, k;
//     cin >> n >> k;

//     string st;
//     cin >> st;

//     unordered_map<char, int> mp;
//     for (ll i = 0; i < k; i++)
//     {
//         char ch;
//         cin >> ch;
//         mp[ch]++;
//     }

//     ll i = 0, j = 0;
//     ll cnt = 0;
//     ll ans = 0;
//     while (j < n)
//     {
//         if (mp.find(st[j]) == mp.end())
//         {
//             // cout << j << " ";
//             cnt = j - i;
//             i = j + 1;
//             ll sum = ((cnt * (cnt + 1)) / 2);
//             ans += sum;
//         }
//         j++;
//     }
//     cout << endl;

//     // cout << j << " ";
//     // cout << cnt << " ";
//     cnt = j - i;
//     // cout << cnt << " ";
//     ans += ((cnt * (cnt + 1)) / 2);

//     cout << ans << endl;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    string st;
    cin >> st;

    vll nums(26, 0);

    for (ll i = 0; i < k; i++)
    {
        char ch;
        cin >> ch;
        nums[ch - 'a']++;
    }

    for (ll i = 0; i < n; i++)
    {
        if (nums[st[i] - 'a'])
        {
            st[i] = 1;
        }
        else
        {
            st[i] = 0;
        }
    }

    vll dp(n + 1);
    ll ans = 0;
    dp[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        if (st[i] == 0)
        {
            dp[i + 1] = 0;
        }
        else
        {
            dp[i + 1] = dp[i] + 1;
        }

        ans += dp[i + 1];
    }

    cout << ans << endl;

    return 0;
}