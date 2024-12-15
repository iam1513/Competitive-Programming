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
        ll m, a, b, c;
        cin >> m >> a >> b >> c;

        ll r1 = 0, r2 = 0, r = 0, ans = 0;

        if (m - a >= 0)
        {
            ans += a;
            r1 = m - a;
        }
        else
        {
            ans += m;
        }

        if (m - b >= 0)
        {
            ans += b;
            r2 = m - b;
        }
        else
        {
            ans += m;
        }

        r = r1 + r2;

        if (r - c >= 0)
        {
            ans += c;
        }
        else
        {
            ans += r;
        }

        cout << ans << endl;
    }

    return 0;
}