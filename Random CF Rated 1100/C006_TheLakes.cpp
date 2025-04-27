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

ll dfs(vector<vector<ll>> &nums, vector<vector<ll>> &dp, ll i, ll j, ll n, ll m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || dp[i][j] != 0 || nums[i][j] == 0)
        return 0;

    ll sum = nums[i][j];
    dp[i][j] = 1;

    sum += dfs(nums, dp, i + 1, j, n, m);
    sum += dfs(nums, dp, i - 1, j, n, m);
    sum += dfs(nums, dp, i, j + 1, n, m);
    sum += dfs(nums, dp, i, j - 1, n, m);

    return sum;
}

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
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> nums[i][j];
            }
        }

        vector<vector<ll>> dp(n, vector<ll>(m, 0));
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (dp[i][j] == 0 && nums[i][j] != 0)
                {
                    ll sum = dfs(nums, dp, i, j, n, m);
                    ans = max(ans, sum);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}