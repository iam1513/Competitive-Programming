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

    ll n, k, q;
    cin >> n >> k >> q;

    vll nums(1e6 + 5, 0);

    while (n--)
    {
        ll a, b;
        cin >> a >> b;

        nums[a]++;
        nums[b + 1]--;
    }

    for (ll i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
    }

    for (ll i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= k)
        {
            nums[i] = 1;
        }
        else
        {
            nums[i] = 0;
        }
    }

    vll ps(1e6 + 5, 0);
    for (ll i = 1; i < ps.size(); i++)
    {
        ps[i] = nums[i] + ps[i - 1];
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        ll ans = (ps[b] - ps[a - 1]);
        cout << ans << endl;
    }

    return 0;
}