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

using namespace std;

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

void take_input_vector(vll &v, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void print_vector_to_debug(vll &v, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

ll recom(vll &a, ll k, ll l, ll r)
{
    ll n = a.size();
    if (k < 0)
        return 0;

    ll lft = 0, cnt = 0;
    mll f;

    for (ll rgt = 0; rgt < n; rgt++)
    {
        f[a[rgt]]++;

        while (f.size() > k)
        {
            f[a[lft]]--;
            if (f[a[lft]] == 0)
            {
                f.erase(a[lft]);
            }
            lft++;
        }

        ll mnSt = rgt - r + 1;
        ll mxSt = rgt - l + 1;
        ll vMn = max(lft, mnSt);
        ll vMx = min(rgt, mxSt);

        if (vMn <= vMx && vMx >= 0)
        {
            cnt += (vMx - vMn + 1);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k, l, r;
        cin >> n >> k >> l >> r;

        vll a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll res = recom(a, k, l, r) - recom(a, k - 1, l, r);
        cout << res << endl;
    }

    return 0;
}