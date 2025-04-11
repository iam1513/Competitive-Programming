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
        ll n, m, q;
        cin >> n >> m >> q;

        ll t1, t2;
        cin >> t1 >> t2;

        ll temp1 = t1;
        ll temp2 = t2;
        if (t1 > t2)
        {
            t1 = temp2;
            t2 = temp1;
        }

        ll d;
        cin >> d;
        ll ans = 0;
        if (t1 == d || t2 == d)
        {
            cout << 0 << endl;
            continue;
        }
        if (t1 < d && t2 > d)
        {
            ans = (t2 - t1) / 2;
        }
        else if (d < t1)
        {
            ans = t1 - 1;
        }
        else
        {
            ans = n - t2;
        }

        cout << ans << endl;
    }

    return 0;
}