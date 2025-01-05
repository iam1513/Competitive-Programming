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

bool recom(string &st, ll i, ll n, ll m, ll k)
{
    if (i == n)
    {
        return true;
    }

    if (k == 0 || st[i] == 'C' || k == 0)
    {
        return false;
    }

    ll canReach = false;

    if (st[i] == 'W')
    {
        canReach = recom(st, i + 1, n, m, k - 1);
    }

    if (st[i] == 'L')
    {
        for (ll j = 1; j <= m; j++)
        {
            canReach = canReach || recom(st, i + j, n, m, k);
        }
    }

    return canReach;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;

        string st;
        cin >> st;

        bool ans = recom(st, 0, n, m, k);

        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}