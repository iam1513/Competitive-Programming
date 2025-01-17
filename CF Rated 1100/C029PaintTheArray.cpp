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

using namespace std;

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
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        ll gcd_even = nums[0];
        for (ll i = 2; i < n; i += 2)
        {
            gcd_even = __gcd(gcd_even, nums[i]);
        }

        ll gcd_odd = nums[1];
        for (ll i = 1; i < n; i += 2)
        {
            gcd_odd = __gcd(gcd_odd, nums[i]);
        }

        bool flag1 = true;
        for (ll i = 1; i < n; i += 2)
        {
            if (nums[i] % gcd_even == 0)
            {
                flag1 = false;
            }
        }

        bool flag2 = true;
        for (ll i = 0; i < n; i += 2)
        {
            if (nums[i] % gcd_odd == 0)
            {
                flag2 = false;
            }
        }

        if (flag1 && flag2)
        {
            if (gcd_even <= gcd_odd && gcd_even != 1)
            {
                cout << gcd_even << endl;
            }
            else if (gcd_even > gcd_odd && gcd_odd != 1)
            {
                cout << gcd_odd << endl;
            }
        }
        else if (flag1 && gcd_even != 1)
        {
            cout << gcd_even << endl;
        }
        else if (flag2 && gcd_odd != 1)
        {
            cout << gcd_odd << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}