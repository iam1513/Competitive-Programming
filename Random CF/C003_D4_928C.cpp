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

int sum(int i)
{
    ll res = 0;
    while (i > 0)
    {
        res += i % 10;
        i /= 10l;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    vll dp(2e5 + 1, 0);

    ll s = 1, temp = 1;
    ll cnt = 0;
    for (ll i = 1; i <= 2e5; i++)
    {
        dp[i] = dp[i - 1] + sum(i);
    }

    while (t--)
    {
        ll n;
        cin >> n;

        cout << dp[n] << endl;
    }

    return 0;
}