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

    ll n, k, x;
    cin >> n >> k >> x;

    vll nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    ll ans = 1;

    vll gaps;

    for (ll i = 0; i < n - 1; i++)
    {
        if (nums[i + 1] - nums[i] > x)
        {
            gaps.push_back(nums[i + 1] - nums[i]);
        }
    }

    sort(gaps.begin(), gaps.end());

    for (ll i = 0; i < gaps.size(); i++)
    {
        ll need = ((gaps[i] - 1) / x);
        if (need <= k)
        {
            k -= need;
        }
        else
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}