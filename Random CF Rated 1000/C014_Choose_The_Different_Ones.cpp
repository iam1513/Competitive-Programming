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
        ll n, m, k;
        cin >> n >> m >> k;

        vll a(n), b(m);
        ll k1, k2;
        vll cnt(k + 1, 0);
        sl s1, s2;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= k)
            {
                s1.insert(a[i]);
                cnt[a[i]]++;
            }
        }

        for (ll i = 0; i < m; i++)
        {
            cin >> b[i];
            if (b[i] <= k)
            {
                s2.insert(b[i]);
                cnt[b[i]]++;
            }
        }

        k1 = s1.size(), k2 = s2.size();

        bool flag = true;

        for (ll i = 1; i <= k; i++)
        {
            if (cnt[i] == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag && k1 >= k / 2 && k2 >= k / 2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}