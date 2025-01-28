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

        vll nums(n + 1);
        mll mp;
        for (ll i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }

        vll ps(n + 1);
        ps[0] = 0;

        vll lst(n + 1);
        mp[0] = 0;

        for (ll i = 1; i <= n; i++)
        {
            ps[i] = ps[i - 1] + nums[i];
            if (mp.find(ps[i]) == mp.end())
            {
                lst[i] = -1;
            }
            else
            {
                lst[i] = mp[ps[i]];
            }
            mp[ps[i]] = i;
        }

        vll dp(n + 1, 0);

        for (ll i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i], dp[i - 1]);
            if (lst[i] != -1)
            {
                dp[i] = max(dp[i], dp[lst[i]] + 1);
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            cout << ps[i] << " ";
        }
        cout << endl;

        for (ll i = 1; i <= n; i++)
        {
            cout << lst[i] << " ";
        }
        cout << endl;

        for (auto m : mp)
        {
            cout << m.first << " " << m.second << " + ";
        }
        cout << endl;

        for (ll i = 1; i <= n; i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;

        cout << *max_element(dp.begin(), dp.end()) << endl;
    }

    return 0;
}