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
        ll n, s;
        cin >> n >> s;

        vll nums(n);
        take_input_vector(nums, n);

        ll ans = 0;

        ll mini = *min_element(nums.begin(), nums.end());
        ll maxi = *max_element(nums.begin(), nums.end());

        if (mini >= s)
        {
            ans = maxi - s;
            cout << ans << "\n";
            continue;
        }
        if (maxi <= s)
        {
            ans = s - mini;
            cout << ans << "\n";
            continue;
        }

        ll sm = (s - mini);
        ll lar = maxi - s;

        ll a = min(sm, lar);
        ll b = max(sm, lar);

        ans = a * 2 + b;

        cout << ans << "\n";
    }

    return 0;
}