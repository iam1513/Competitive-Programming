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
        ll n, q;
        cin >> n >> q;

        vll hs(n), qs(q);
        vll maxi(n), ps(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> hs[i];
            if (i == 0)
            {
                maxi[0] = hs[0];
                ps[0] = hs[0];
            }
            else
            {
                maxi[i] = max(maxi[i - 1], hs[i]);
                ps[i] = ps[i - 1] + hs[i];
            }
        }

        for (ll i = 0; i < q; i++)
        {
            cin >> qs[i];
        }

        vll ansV(q);

        for (ll i = 0; i < q; i++)
        {
            ll lo = 0, hi = n - 1;
            ll ans = -1;
            while (lo <= hi)
            {
                ll mid = lo + (hi - lo) / 2;
                if (maxi[mid] > qs[i])
                {

                    hi = mid - 1;
                }
                else
                {
                    ans = mid;
                    lo = mid + 1;
                }
            }
            if (ans == -1)
            {
                ansV[i] = 0;
                continue;
            }

            ansV[i] = ps[ans];
        }

        for (ll i = 0; i < q; i++)
        {
            cout << ansV[i] << " ";
        }
        cout << endl;
    }

    return 0;
}