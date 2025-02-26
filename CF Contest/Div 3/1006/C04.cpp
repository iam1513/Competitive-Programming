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
        if (is_sorted(nums.begin(), nums.end()))
        {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        ll x = 0;
        ll y = 0;
        ll cnt = INT_MIN;
        for (ll i = 0; i < n - 1; i++)
        {
            ll nc = 0;
            for (ll j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i])
                {
                    nc++;
                }
                else if (nums[j] > nums[i])
                {
                    nc--;
                }

                if (nc > cnt)
                {
                    x = i;
                    y = j;
                    cnt = nc;
                }
            }
        }

        cout << x + 1 << " " << y + 1 << endl;
    }

    return 0;
}