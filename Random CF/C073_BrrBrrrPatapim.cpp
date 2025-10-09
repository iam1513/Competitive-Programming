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

using namespace std;

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

void take_input_vector(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}

void print_vector_to_debug(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

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

        ll m = 2 * n;

        vll ans(m + 1, 0);
        mll mp;

        vector<vector<ll>> grid(n, vector<ll>(n));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                ll num = i + j + 2;
                if (num <= m && mp.find(grid[i][j]) == mp.end())
                {
                    ans[num] = grid[i][j];
                    mp[grid[i][j]]++;
                }
            }
        }

        ll first = -1;

        for (ll i = 1; i <= m; i++)
        {
            if (mp.find(i) == mp.end())
            {
                first = i;
                break;
            }
        }

        ans[1] = first;

        for (ll i = 1; i <= m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}