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

        vll nums(n);
        take_input_vector(nums, n);

        vll cnt(31, 0);
        ll t = 0;
        for (ll i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                t++;
            }
            for (ll j = 0; j <= 30; j++)
            {
                if ((nums[i]) & (1 << j))
                {
                    cnt[j]++;
                }
            }
        }

        // cout << "t " << t << "\n";
        ll ans = 0;
        for (ll i = 0; i <= 30; i++)
        {
            // cout << cnt[i] << " ";
            if (ans == 0)
            {
                ans = cnt[i];
                // cout << ans << "\n";
            }
            else
            {
                ans = gcd(ans, cnt[i]);
            }
        }

        if (t == n)
        {
            for (ll i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            for (ll i = 1; i <= ans / 2; i++)
            {
                if ((ans % i) == 0)
                {
                    cout << i << " ";
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}