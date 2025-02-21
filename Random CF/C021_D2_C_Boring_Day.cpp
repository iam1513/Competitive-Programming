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
        ll n, l, r;
        cin >> n >> l >> r;

        vll nums(n + 1);

        for (ll i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }

        vll ps(n + 1, 0);
        ps[0] = 0;

        for (ll i = 1; i <= n; i++)
        {
            ps[i] = ps[i - 1] + nums[i];
        }

        ll ans = 0;
        ll last = 0;

        for (ll i = 1; i <= n; i++)
        {
            ll low = last, high = i;
            ll best = -1;

            while (low <= high)
            {
                ll mid = (low + high) / 2;
                ll sum = ps[i] - ps[mid];

                if (sum >= l && sum <= r)
                {
                    best = mid;
                    low = mid + 1;
                }
                else if (sum < l)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            if (best != -1)
            {
                ans++;
                last = i;
            }
        }

        cout << ans << endl;
    }

    return 0;
}