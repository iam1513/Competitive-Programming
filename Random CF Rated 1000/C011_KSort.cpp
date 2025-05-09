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

        vll temp;
        ll num = nums[0];
        for (ll i = 1; i < n; i++)
        {
            if (nums[i] > num)
            {
                num = nums[i];
            }
            else
            {
                temp.push_back(num - nums[i]);
            }
        }

        sort(temp.begin(), temp.end());

        if (temp.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }

        ll cnt = temp.size() + 1;
        ll ans = temp[0] * (cnt);

        for (ll i = 1; i < temp.size(); i++)
        {
            ans += (temp[i] - temp[i - 1]) * (cnt - i);
        }

        cout << ans << endl;
    }

    return 0;
}