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

        vll nums(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        sort(nums.rbegin(), nums.rend());
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        vector<pair<ll, ll>> p;

        for (ll i = 0; i < n;)
        {
            ll j = i;
            while (i < n && nums[i] == nums[j])
            {
                i++;
            }

            p.push_back({nums[j], i - j});
        }

        // for (ll i = 0; i < p.size(); i++)
        // {
        //     cout << p[i].first << " " << p[i].second << endl;
        // }

        ll s = p.size();

        ll ans = p[0].second;

        for (ll i = 1; i < s; i++)
        {
            if (p[i].first + 1 == p[i - 1].first)
            {
                ans += max(p[i].second - p[i - 1].second, 0ll);
            }
            else
            {
                ans += p[i].second;
            }
        }

        cout << ans << endl;
    }

    return 0;
}