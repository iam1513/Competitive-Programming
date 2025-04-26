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
        vll nums(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            nums[i] = x;
        }
        string st;
        cin >> st;

        unordered_map<ll, ll> dp;

        for (ll i = 1; i <= n; i++)
        {
            if (!dp[nums[i]])
            {
                dp[nums[i]] = nums[i];
                ll x = nums[i];
                ll y = nums[x];
                while (x != y)
                {
                    dp[y] = x;
                    y = nums[y];
                }
            }
        }

        // print_vector_to_debug(dp, n + 1);
        // for (auto ele : dp)
        // {
        //     cout << ele.first << " " << ele.second << "\n";
        // }

        unordered_map<ll, ll> dp1;
        for (auto ele : dp)
        {
            if (st[ele.first - 1] == '0')
            {
                dp1[ele.second]++;
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            ll x = dp[i];
            cout << dp1[x] << " ";
        }
        cout << endl;
    }

    return 0;
}
