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
    for (ll i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
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
        vll nums(n + 1);
        take_input_vector(nums, n);

        ll q;
        cin >> q;

        vector<int> idx(n + 2, n + 1); 
        for (int i = n - 1; i >= 1; i--)
        {
            if (nums[i] == nums[i + 1])
                idx[i] = idx[i + 1];
            else
                idx[i] = i + 1;
        }

        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            if (idx[l] <= r)
            {
                cout << l << " " << idx[l] << '\n';
            }
            else
            {
                cout << -1 << " " << -1 << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}
