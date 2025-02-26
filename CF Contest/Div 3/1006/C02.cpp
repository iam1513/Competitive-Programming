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

        string st;
        cin >> st;
        ll f = 0, s = 0;
        for (ll i = 0; i < st.size(); i++)
        {
            if (st[i] == '-')
            {
                f++;
            }
            else
            {
                s++;
            }
        }

        ll x = 0, y = 0;

        if (f < 2 || s < 1)
        {
            cout << 0 << endl;
            continue;
        }

        if (f % 2 == 1)
        {
            x = f / 2 + 1;
            y = f / 2;
        }
        else
        {
            x = f / 2;
            y = x;
        }

        ll prod = y * s * x;

        cout << prod << endl;
    }

    return 0;
}