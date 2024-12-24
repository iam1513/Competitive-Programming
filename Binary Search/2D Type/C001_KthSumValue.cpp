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

bool check(ll x, vll &a, vll &b, ll k)
{
    ll cnt = 0;

    for (ll i = 0; i < a.size(); i++)
    {
        cnt += upper_bound(b.begin(), b.end(), x - a[i]) - b.begin();
    }

    return cnt >= k;
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

        vll a(n), b(m);

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (ll i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (n > m)
        {
            swap(n, m);
            swap(a, b);
        }

        ll lo = a[0] + b[0], hi = a[n - 1] + b[m - 1];
        ll ans = -1;

        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if (check(mid, a, b, k))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}