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

        ll m = (n) * (n - 1) / 2;
        vll nums(m);

        for (ll i = 0; i < m; i++)
        {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        ll ans = 0;

        ll cnt = 0;
        if (n == 2)
        {
            ans = nums[0];
        }
        else if (n == 3)
        {
            ans = nums[0] + nums[1];
        }
        else
        {
            ll cnt = 3;
            ans = nums[0] + nums[1];

            ll l = 3;
            while (l < m)
            {
                ans += nums[l];
                // cout << "l : " << l << endl;
                l += cnt;
                cnt++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}