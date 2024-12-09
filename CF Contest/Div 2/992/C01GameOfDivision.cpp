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
        ll n, k;
        cin >> n >> k;

        vector<ll> nums;

        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            nums.push_back(a);
        }

        ll ans = -1;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            cnt = 0;
            for (ll j = 0; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) % k != 0 && i != j)
                {

                    cnt++;
                }
            }

            if (cnt == n - 1)
            {
                ans = i;
                break;
            }
        }

        ans == -1 ? cout << "NO" << endl : cout << "YES" << "\n"
                                                << ans + 1 << endl;
    }

    return 0;
}