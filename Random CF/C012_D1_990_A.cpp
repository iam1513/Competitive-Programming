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
        ll n;
        cin >> n;

        vll r1(n), r2(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> r1[i];
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> r2[i];
        }

        vector<pair<ll, ll>> nums(n);

        for (ll i = 0; i < n; i++)
        {
            nums[i].first = r1[i];
            nums[i].second = r2[i];
        }

        ll ans = LLONG_MIN;

        for (ll i = 0; i < n; i++)
        {
            ll sum = nums[i].first + nums[i].second;
            for (ll j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += max(nums[j].first, nums[j].second);
                }
            }

            ans = max(ans, sum);
        }

        cout << ans << endl;
    }

    return 0;
}