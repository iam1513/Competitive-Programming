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

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vll nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    map<ll, map<ll, ll>> mp;
    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        ans += mp[(x - nums[i] % x) % x][nums[i] % y];
        mp[nums[i] % x][nums[i] % y]++;
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}