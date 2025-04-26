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
        ll n, m;
        cin >> n >> m;

        vll nums(n + 1);
        nums[0] = INT_MIN;
        for (ll i = 1; i <= n; i++)
        {
            cin >> nums[i];
        }

        ll b;
        cin >> b;

        vll dp(n + 1, 0);
        dp[0] = INT_MIN;
        bool ok = true;

        for (ll i = 1; i <= n; i++)
        {
            ll normal = nums[i];
            ll flipped = b - nums[i];

            if (normal >= dp[i - 1] && flipped >= dp[i - 1])
            {
                dp[i] = min(normal, flipped);
            }
            else if (normal >= dp[i - 1])
            {
                dp[i] = normal;
            }
            else if (flipped >= dp[i - 1])
            {
                dp[i] = flipped;
            }
            else
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}