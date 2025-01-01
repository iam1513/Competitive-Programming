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

    ll n, q;
    cin >> n >> q;

    vll nums(1e6, 0);

    for (ll i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    vll temp(1e6, 0);

    for (ll i = 1; i <= n; i++)
    {
        temp[i] = (nums[i] * i) % MOD;
    }

    temp[0] %= MOD;
    for (ll i = 1; i <= n; i++)
    {
        temp[i] += temp[i - 1];
        temp[i] %= MOD;
    }

    nums[0] %= MOD;
    for (ll i = 1; i <= n; i++)
    {
        nums[i] += nums[i - 1];
        nums[i] %= MOD;
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        ll ans = temp[b] - temp[a - 1];
        ans -= (a - 1) * (nums[b] - nums[a - 1]);
        ans = (ans % MOD + MOD) % MOD;

        cout << ans << endl;
    }

    return 0;
}