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

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a, b;

        for (ll i = 0; i < n; i++)
        {
            ll z;
            cin >> z;
            a.push_back(z);
        }

        for (ll i = 0; i < n; i++)
        {
            ll z;
            cin >> z;
            b.push_back(z);
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        ll ans = 1;
        for (ll i = 0; i < n; i++)
        {
            ll cnt = a.size() - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
            ans = ans * max(cnt - i, 0LL) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}