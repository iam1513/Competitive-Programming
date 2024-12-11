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
        string a, b;
        cin >> a >> b;

        set<string> as, bs;

        for (ll i = 0; i < a.size(); i++)
        {
            for (ll j = 1; j <= a.size(); j++)
            {

                string s = a.substr(i, j);
                as.insert(s);
            }
        }

        for (ll i = 0; i < b.size(); i++)
        {
            for (ll j = 1; j <= b.size(); j++)
            {

                string s = b.substr(i, j);
                bs.insert(s);
            }
        }

        ll maxi = LLONG_MIN;

        for (const auto &str_a : as)
        {
            for (const auto &str_b : bs)
            {
                if (str_a == str_b)
                {
                    maxi = max(maxi, static_cast<long long>(str_a.size()));
                }
            }
        }

        cout << a.size() + b.size() - maxi * 2 << endl;
    }

    return 0;
}
