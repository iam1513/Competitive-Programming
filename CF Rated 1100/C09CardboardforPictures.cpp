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
        ll n, val;
        cin >> n >> val;

        vector<ll> nums;

        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            nums.push_back(a);
        }

        ll lo = 1, hi = 1'000'000'007;

        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll sum = 0;
            for (ll i = 0; i < n; i++)
            {
                sum += (nums[i] + 2 * mid) * (nums[i] + 2 * mid);
                if (sum > val)
                {
                    break;
                }
            }

            if (sum == val)
            {
                cout << mid << endl;
                break;
            }

            if (sum > val)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
    }

    return 0;
}