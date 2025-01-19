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
        ll n, x, y;
        cin >> n >> x >> y;

        ll x_can_get = n / x;
        ll y_can_get = n / y;
        ll x_and_y = n / (lcm(x, y));

        x_can_get -= x_and_y;
        y_can_get -= x_and_y;

        ll ans = 0;
        ll total_sum = (n) * (n + 1) / 2;
        ll to_add = total_sum - (n - x_can_get) * (n - x_can_get + 1) / 2;
        ll to_sub = (y_can_get) * (y_can_get+1) / 2;

        ans = to_add - to_sub;

        cout << ans << endl;
    }

    return 0;
}
