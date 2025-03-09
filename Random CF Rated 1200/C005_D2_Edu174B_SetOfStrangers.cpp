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
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> nums(n, vector<ll>(m));
        mll mp;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> nums[i][j];
                mp[nums[i][j]] = 1;
            }
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (i + 1 < n && nums[i][j] == nums[i + 1][j])
                {
                    mp[nums[i][j]] = 2;
                }
                if (j + 1 < m && nums[i][j] == nums[i][j + 1])
                {
                    mp[nums[i][j]] = 2;
                }
            }
        }

        ll maxi = 0;
        ll sum = 0;
        for (auto ele : mp)
        {
            sum += ele.second;
            maxi = max(maxi, ele.second);
        }

        cout << sum - maxi << endl;
    }

    return 0;
}