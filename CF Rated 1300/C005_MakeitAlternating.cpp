#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>

#define pb push_back

#define MOD 998'244'353
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

void upd(ll &a, ll b)
{
    a = (a * 1LL * b) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        ll res = 1;
        ll k = s.size();
        ll n = s.size();
        for (ll l = 0; l < n;)
        {
            ll r = l + 1;
            while (r < n && s[l] == s[r])
                ++r;
            upd(res, r - l);
            --k;
            l = r;
        }

        for (ll i = 1; i <= k; ++i)
            upd(res, i);
        cout << k << ' ' << res << endl;
    }

    return 0;
}