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

    string st;
    cin >> st;

    ll nb, ns, nc;
    cin >> nb >> ns >> nc;

    ll pb, ps, pc;
    cin >> pb >> ps >> pc;

    ll r;
    cin >> r;

    ll b = 0, s = 0, c = 0;

    for (ll i = 0; i < st.size(); i++)
    {
        if (st[i] == 'B')
        {
            b++;
        }
        if (st[i] == 'S')
        {
            s++;
        }
        if (st[i] == 'C')
        {
            c++;
        }
    }

    ll lo = 0, hi = r + 200;

    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        ll r1 = max(b * mid - nb, 0LL);
        ll r2 = max(s * mid - ns, 0LL);
        ll r3 = max(c * mid - nc, 0LL);
        ll priceTotal = r1 * pb + r2 * ps + r3 * pc;
        if (priceTotal > r)
        {

            hi = mid - 1;
        }
        else
        {
            ans = mid;
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}