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

ll fun(ll mod, ll a, ll b, ll c)
{

    if (mod == 0)
    {
        return 0;
    }

    if (mod - a <= 0)
    {
        return 1;
    }

    if (mod - a - b <= 0)
    {
        return 2;
    }

    if (mod - a - b - c <= 0)
    {
        return 3;
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
        ll n, a, b, c;
        cin >> n >> a >> b >> c;

        ll sum = a + b + c;

        // while (sum <= n)
        // {
        //     if (cnt % 3 == 0)
        //     {
        //         sum += a;
        //         cnt++;
        //     }
        //     if (cnt % 3 == 1)
        //     {
        //         sum += b;
        //         cnt++;
        //     }
        //     if (cnt % 3 == 2)
        //     {
        //         sum += c;
        //         cnt++;
        //     }
        // }

        // cout << cnt << endl;

        ll mod = n % sum;
        ll mul = n / sum;

        ll ans = 3 * mul;

        ll cnt = fun(mod, a, b, c);

        cout << ans + cnt << endl;
    }

    return 0;
}