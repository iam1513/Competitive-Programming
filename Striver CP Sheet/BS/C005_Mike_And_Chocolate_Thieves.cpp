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

ll check(ll mid)
{
    ll ans = 0;

    for (ll i = 2; i * i * i <= mid; i++)
    {
        ans += mid / (i * i * i);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll lo = 0, hi = 1e18;
    ll ans = -1;

    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        ll num = check(mid);

        if (num == n)
        {
            ans = mid;
        }
        if (num >= n)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}