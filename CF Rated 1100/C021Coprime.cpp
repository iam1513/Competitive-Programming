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

    ll t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> pairs(1001);
        for (int i = 1; i <= 1000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                if (__gcd(i, j) == 1)
                {
                    pairs[i].push_back(j);
                }
            }
        }

        vector<ll> id[1001];
        for (ll i = 1; i <= n; ++i)
        {
            ll x;
            cin >> x;
            id[x].push_back(i);
        }

        ll ans = -1;
        for (ll i = 1; i <= 1000; ++i)
        {
            for (ll j : pairs[i])
            {
                if (!id[i].empty() && !id[j].empty())
                {

                    ans = max(ans, id[i].back() + id[j].back());
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}