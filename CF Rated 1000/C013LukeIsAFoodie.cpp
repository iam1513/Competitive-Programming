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

        vll nums(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }

        ll num_min = nums[1];
        ll num_max = nums[1];
        ll res = 0;
        for (ll i = 2; i <= n; i++)
        {
            if (nums[i] > num_max)
            {
                num_max = nums[i];
            }
            if (nums[i] < num_min)
            {
                num_min = nums[i];
            }
            if (num_max - num_min > 2 * x)
            {
                res++;
                num_min = num_max = nums[i];
            }
        }
        cout << res << endl;
    }

    return 0;
}
