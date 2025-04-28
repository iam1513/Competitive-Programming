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

ll f(ll n, vector<ll> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        ll temp1 = n + 3 > 0 ? n + 3 : INT_MAX;
        ll temp2 = n + 5 > 0 ? n + 5 : INT_MAX;
        return min(temp1, temp2);
    }

    if (dp[n] != INT_MAX)
    {
        return dp[n];
    }

    return dp[n] = min(f(n - 3, dp), f(n - 5, dp));
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

        // ll ans = INT_MAX;
        vector<ll> dp(n + 1, INT_MAX);
        cout << f(n, dp) << endl;

        // cout << ans << endl;
    }

    return 0;
}
