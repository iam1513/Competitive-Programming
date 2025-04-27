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

        vll a(n + 1), b(m + 1);
        a[0] = INT_MIN, b[0] = INT_MIN;

        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (ll i = 1; i <= m; i++)
        {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        for (ll i = 1; i <= n; i++)
        {

            // Custom binary search
            auto it = partition_point(b.begin(), b.end(), [&](ll x)
                                      { return x - a[i] < a[i - 1]; });

            if (it == b.end())
                continue;

            ll j = *it;

            if (a[i] < a[i - 1] && j - a[i] < a[i - 1])
                continue;

            a[i] = min((a[i] < a[i - 1] ? LLONG_MAX : a[i]), (j - a[i] < a[i - 1] ? LLONG_MAX : j - a[i]));
        }

        cout << (is_sorted(a.begin() + 1, a.end()) ? "YES" : "NO") << '\n';
    }

    return 0;
}