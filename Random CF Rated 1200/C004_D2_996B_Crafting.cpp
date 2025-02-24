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

        vll a(n), b(n);
        vll nums;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (ll i = 0; i < n; i++)
        {
            ll ab = a[i] - b[i];
            nums.push_back(ab);
        }

        sort(nums.begin(), nums.end());

        bool flag = true;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                cnt++;
                if (cnt == 2)
                {
                    break;
                }
            }
        }
        ll f = -1;
        for (ll i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                f = nums[i];
                break;
            }
        }

        if (cnt > 1 || f == -1)
        {
            flag = false;
        }

        if (cnt == 1 && abs(nums[0]) > f)
        {
            flag = false;
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}