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

    ll n, k;
    cin >> n >> k;

    ll lo = 0, hi = k - 1;
    ll ans = -1;
    ll sum = (((k - 1) * (k)) / 2) + 1;
    if (sum < n)
    {
        cout << ans << endl;
    }
    else
    {
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll new_sum = ((mid) * (mid + 1)) / 2;
            if ((sum - new_sum) >= n)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        cout << k - 1 - ans << endl;
    }

    return 0;
}