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

        vector<pair<ll, ll>> a, b, c;
        for (ll i = 0; i < n; i++)
        {
            ll z;
            cin >> z;
            a.push_back({z, i});
        }
        for (ll i = 0; i < n; i++)
        {
            ll z;
            cin >> z;
            b.push_back({z, i});
        }
        for (ll i = 0; i < n; i++)
        {
            ll z;
            cin >> z;
            c.push_back({z, i});
        }

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());
        // for (ll i = 0; i < 3; i++)
        // {
        //     cout << a[i].second << " " << a[i].first << endl;
        // }
        // cout << endl;
        // for (ll i = 0; i < 3; i++)
        // {
        //     cout << b[i].second << " " << b[i].first << endl;
        // }
        // cout << endl;
        // for (ll i = 0; i < 3; i++)
        // {
        //     cout << c[i].second << " " << c[i].first << endl;
        // }
        // cout << endl;

        ll ans = 0;
        for (ll i = 0; i < 3; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                for (ll k = 0; k < 3; k++)
                {
                    if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second)
                    {
                        ans = max(ans, (a[i].first + b[j].first + c[k].first));
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}