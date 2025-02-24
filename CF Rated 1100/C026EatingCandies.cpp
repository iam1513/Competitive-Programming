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

        vll ps(n, 0);
        ps[0] = nums[0];
        for (ll i = 1; i < n; i++)
        {
            ps[i] = nums[i] + ps[i - 1];
        }

        vll ss(n, 0);
        ss[n - 1] = nums[n - 1];

        for (ll i = n - 2; i >= 0; i--)
        {
            ss[i] = nums[i] + ss[i + 1];
        }

        ll i = 0, j = n - 1;
        ll ans = 0;

        // for (ll i = 0; i < n; i++)
        // {
        //     cout << ps[i] << " ";
        // }
        // cout << endl;
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << ss[i] << " ";
        // }
        // cout << endl;

        while (i < j)
        {
            if (ps[i] == ss[j])
            {
                ans = n - j + 1 + i;
            }
            if (ps[i] < ss[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}