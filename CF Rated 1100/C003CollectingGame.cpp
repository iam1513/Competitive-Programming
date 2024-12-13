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

        vector<pair<ll, ll>> p;
        for (ll i = 1; i <= n; i++)
        {
            ll a;
            cin >> a;
            p.push_back({a, i});
        }

        sort(p.begin(), p.end());

        vector<ll> dp(n + 1, 0);
        dp[n] = n - 1;

        vector<ll> ans(n + 1, 0);
        ans[p[n - 1].second] = dp[n];
        vector<ll> pre_sum(n + 1, 0);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += p[i].first;
            pre_sum[i + 1] = sum;
        }

        for (ll i = n - 1; i > 0; i--)
        {
            ll j = i - 1;
            if (pre_sum[i] >= p[i].first)
            {
                // cout << "ONE" << "\n";
                // cout << "presum " << pre_sum[i] << " " << " first " << p[i].first << " idx " << p[i].second << "\n\n";
                dp[i] = dp[i + 1];
                ans[p[i - 1].second] = dp[i];
            }
            else
            {
                // cout << "TWO" << "\n";
                // cout << "presum " << pre_sum[i] << " " << " first " << p[i].first << " idx " << p[i].second << "\n\n";
                dp[i] = i - 1;
                ans[p[i - 1].second] = dp[i];
            }
        }

        // cout << p[0].first << endl;
        if (n > 1 && pre_sum[1] >= p[1].first)
        {
            dp[1] = dp[2];
            ans[p[0].second] = dp[1];
        }
        // cout << endl;
        // for (ll i = 1; i < n + 1; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;

        for (ll i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}