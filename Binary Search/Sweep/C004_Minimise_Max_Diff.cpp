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

bool check(ll maxSeparation, vll &points, ll k)
{
    ll needed = 0;
    for (ll i = 1; i < points.size(); i++)
    {
        ll gap = points[i] - points[i - 1];
        needed += (gap - 1) / maxSeparation; 
        if (needed > k)
            return false; 
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vll nums(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        ll maxi = 0, maxiIdx = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            if (maxi < nums[i + 1] - nums[i])
            {
                maxi = nums[i + 1] - nums[i];
                maxiIdx = i;
            }
        }

        ll lo = 1, hi = 1e9;
        ll ans = hi + 1;

        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (check(mid, nums, k))
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
