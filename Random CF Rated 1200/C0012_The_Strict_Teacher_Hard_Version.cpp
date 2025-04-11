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

        vll t(m), d(q);

        for (ll i = 0; i < m; i++)
        {
            cin >> t[i];
        }

        sort(t.begin(), t.end());

        for (ll i = 0; i < q; i++)
        {
            cin >> d[i];
        }

        for (ll i = 0; i < q; i++)
        {
            bool flag = true;
            if (d[i] > t[m - 1])
            {
                cout << n - t[m - 1] << endl;
                flag = false;
            }
            if (d[i] < t[0] && flag)
            {
                cout << t[0] - 1 << endl;
                flag = false;
            }

            if (flag)
            {
                ll ub = upper_bound(t.begin(), t.end(), d[i]) - t.begin();
                ll t1 = t[ub - 1], t2 = t[ub];

                if (t1 == d[i] || t2 == d[i])
                {
                    cout << 0 << endl;
                }

                else
                {
                    ll ans = (t2 - t1) / 2;
                    cout << ans << endl;
                }
            }
        }
    }

    return 0;
}