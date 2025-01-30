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

    ll sum = accumulate(nums.begin(), nums.end(), 0LL);

    ll lastAll = -1, lastVal = 0;
    mll lastChangedIndex;

    for (ll i = 0; i < n; i++)
    {
        lastChangedIndex[i] = 0;
    }

    for (ll i = 1; i <= q; i++)
    {
        ll t;
        cin >> t;

        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            if (lastChangedIndex[x] > lastAll)
            {
                sum += (y - nums[x]);
            }
            else
            {
                sum += (y - lastVal);
            }

            nums[x] = y;
            lastChangedIndex[x] = i;
            cout << sum << endl;
        }

        else
        {
            ll x;
            cin >> x;

            lastAll = i;
            lastVal = x;

            sum = x * n;

            cout << sum << endl;
        }
    }

    return 0;
}