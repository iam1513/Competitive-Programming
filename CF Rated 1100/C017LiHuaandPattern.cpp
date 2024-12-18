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
        ll n, k;
        cin >> n >> k;

        vector<vector<ll>> nums(n, vector<ll>(n));

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> nums[i][j];
            }
        }

        ll s = 0, e = n - 1;
        ll diff = 0;
        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < n; ++j)
            {
                if (nums[i][j] != nums[n - i - 1][n - j - 1])
                {
                    ++diff;
                }
            }
        }
        diff /= 2;

        if (diff > k)
        {
            cout << "NO" << endl;
        }
        else
        {
            k -= diff;
            if (n % 2 == 1 || k % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}