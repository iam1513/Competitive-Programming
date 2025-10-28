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

using namespace std;

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

void take_input_vector(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}

void print_vector_to_debug(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

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

        vector<pll> nums;

        while (n--)
        {
            ll x;
            cin >> x;

            ll maxi = INT_MIN;
            for (ll i = 0; i < x; i++)
            {
                ll a;
                cin >> a;
                maxi = max(maxi, a - i);
            }

            nums.pb({maxi + 1, x});
        }

        // for (auto ele : nums)
        // {
        //     cout << ele.first << " " << ele.second << endl;
        // }

        // cout << endl;

        sort(nums.begin(), nums.end());

        // for (auto ele : nums)
        // {
        //     cout << ele.first << " " << ele.second << endl;
        // }

        ll total_gain = 0;
        ll ans = 0;
        for (ll i = 0; i < nums.size(); i++)
        {
            ans = max(ans, nums[i].first - total_gain);
            total_gain += nums[i].second;
        }

        cout << ans << endl;
    }

    return 0;
}