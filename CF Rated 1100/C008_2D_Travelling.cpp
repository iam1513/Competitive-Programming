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
        ll n, k, a, b;
        cin >> n >> k >> a >> b;

        ll x1, y1;
        ll x2, y2;

        vector<pll> nums;

        for (ll i = 0; i < n; i++)
        {
            ll one, two;
            cin >> one >> two;

            nums.push_back({one, two});

            if (i == a - 1)
            {
                x1 = one, y1 = two;
            }
            if (i == b - 1)
            {
                x2 = one, y2 = two;
            }
        }

        ll mini1 = LLONG_MAX, mini2 = LLONG_MAX;

        for (ll i = 0; i < k; i++)
        {

            ll diff1 = abs(x1 - nums[i].first) + abs(y1 - nums[i].second);
            mini1 = min(mini1, diff1);

            ll diff2 = abs(x2 - nums[i].first) + abs(y2 - nums[i].second);
            mini2 = min(mini2, diff2);
        }

        ll mini3 = abs(x1 - x2) + abs(y1 - y2);
        // cout << "HERE" << mini3 << endl;
        ll new_mini = mini1 + mini2;
        if (mini1 == LLONG_MAX || mini2 == LONG_MAX)
        {
            new_mini = LLONG_MAX;
        }
        cout << min(new_mini, mini3) << endl;
    }

    return 0;
}