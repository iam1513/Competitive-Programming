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
        mll mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        if (n == 1 && nums[0] != 0)
        {
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;

        if (nums[0] == 0)
        {
            ans++;
        }

        ll sum = nums[0];
        mp[nums[0]] = 1;

        for (ll i = 1; i < n; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
            ll to_find = sum / 2;
            if (sum % 2 == 0)
            {
                if (mp.find(to_find) != mp.end())
                {
                    ans += 1;
                }
            }
            // cout << nums[i] << " ";
        }

        cout << ans << endl;
    }

    return 0;
}