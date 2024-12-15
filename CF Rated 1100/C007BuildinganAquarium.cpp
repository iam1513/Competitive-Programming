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
        ll n, x;
        cin >> n >> x;

        vector<ll> nums(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        ll lo = 0, hi = 2'000'000'007; // Can set in this way like 2,000,000,007 in irl

        while (lo < hi)
        {
            ll mid = lo + (hi - lo + 1) / 2;
            ll total = 0;
            for (ll i = 0; i < n; i++)
            {
                total += max(mid - nums[i], 0LL); // To convert 0 to Long Long
            }

            if (total <= x)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        cout << lo << endl;
    }

    return 0;
}