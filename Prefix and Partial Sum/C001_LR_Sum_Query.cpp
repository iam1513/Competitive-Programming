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

    vll nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vll ps(n);
    ps[0] = (nums[0] % MOD + MOD) % MOD;
    for (ll i = 1; i < n; i++)
    {
        ps[i] = (nums[i] % MOD + MOD + ps[i - 1] % MOD + MOD) % MOD;
    }

    while (q--)
    {
        ll s, e;
        cin >> s >> e;

        s == 1 ? cout << (ps[e - 1] % MOD + MOD) % MOD << endl : cout << (ps[e - 1] % MOD + MOD - ps[s - 2] % MOD + MOD) % MOD << endl;
    }

    return 0;
}