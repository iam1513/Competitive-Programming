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
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> cnt;
        vector<vector<ll>> store;
        for (ll i = 0; i < n; i++)
        {
            vll nums(m);
            ll sum = 0;
            for (ll j = 0; j < m; j++)
            {
                cin >> nums[j];
                sum += nums[j];
            }
            cnt.push_back({sum, i});
            store.push_back(nums);
        }

        sort(cnt.rbegin(), cnt.rend());

        ll ans = 0;
        ll total_prefix = 0;
        for (ll i = 0; i < n; i++)
        {
            ll idx = cnt[i].second;
            for (ll j = 0; j < m; j++)
            {
                total_prefix += store[idx][j];
                ans += total_prefix;
            }
        }

        cout << ans << endl;
    }

    return 0;
}