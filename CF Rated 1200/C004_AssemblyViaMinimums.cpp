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
        ll k;
        cin >> k;

        ll n = (k * (k - 1)) / 2;

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

        vll ans;
        ll cnt = 1;

        for (ll i = 0; i < n; i += cnt)
        {
            ans.push_back(nums[i]);
            cnt++;
        }

        sort(ans.begin(), ans.end());

        ll to_push = ans[ans.size() - 1];

        // if (ans[ans.size() - 1] == 1e9 || ans[ans.size() - 1] == -1e9)
        // {
        //     to_push = ans[ans.size() - 1];
        // }

        ans.push_back(to_push);

        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}