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

ll func(ll a, ll b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    if (a < b)
        return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        ll ans = 0;
        if (func(a1, b1) + func(a2, b2) > 0)
        {
            ans += 1;
        }
        if (func(a1, b2) + func(a2, b1) > 0)
        {
            ans += 1;
        }
        if (func(a2, b1) + func(a1, b2) > 0)
        {
            ans += 1;
        }
        if (func(a2, b2) + func(a1, b1) > 0)
        {
            ans += 1;
        }

        cout << ans << endl;
    }

    return 0;
}