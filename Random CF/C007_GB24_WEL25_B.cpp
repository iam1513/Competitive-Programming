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

        vll l(n), r(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i];
        }

        vll nums(2 * n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            if (l[i] == r[i])
            {
                nums[l[i]]++;
            }
        }

        // for (ll i = 0; i < 2 * n + 1; i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        vll ps(2 * n + 2);
        ps[0] = 0;

        for (ll i = 0; i < 2 * n + 1; i++)
        {
            ps[i + 1] = ps[i] + (nums[i] > 0);
        }

        // for (ll i = 0; i < 2 * n + 2; i++)
        // {
        //     cout << ps[i] << " ";
        // }
        // cout << endl;

        string ans;

        for (ll i = 0; i < n; i++)
        {
            ll cnt = ps[r[i] + 1] - ps[l[i]];
            // cout << cnt << endl;
            if (l[i] == r[i] && nums[l[i]] == 1)
                cnt--;
            if (r[i] - l[i] + 1 > cnt)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }

        cout << ans << endl;
    }

    return 0;
}