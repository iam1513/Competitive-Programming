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
        ll m, n;
        cin >> n >> m;

        vll nums(m);

        for (ll i = 0; i < m; i++)
        {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        vll diff;
        diff.push_back(n - nums[m - 1] + nums[0] - 1);
        for (ll i = 0; i < m - 1; i++)
        {
            diff.push_back(nums[i + 1] - nums[i] - 1);
        }

        sort(diff.rbegin(), diff.rend());

        ll not_inf = 0;

        ll cnt = 0;

        for (ll i = 0; i < diff.size(); i++)
        {
            if (diff[i] - 2 * cnt > 0)
            {
                not_inf += max(1LL, (diff[i] - 2 * cnt - 1));
                cnt += 2;
            }
        }

        cout << n - not_inf << endl;
    }

    return 0;
}