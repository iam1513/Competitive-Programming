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

    ll a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 1 << endl;
        cout << a << endl;
    }
    else if (b > 0)
    {
        cout << 4 << endl;
        ll s = b, t = b, fr = b + 1;
        ll sum = s + t + fr;
        ll f = a * 4 - sum;

        if (f > fr)
        {
            ll temp = f;
            f = fr;
            fr = temp;
        }

        if (f > s)
        {
            ll to_sub = f - s;
            f -= to_sub;
            fr += to_sub;
        }
        cout << f << " " << s << " " << t << " " << fr << endl;
    }
    else
    {
        cout << 3 << endl;
        ll f = b, s = b;
        ll t = a * 3 - 2 * b;
        cout << f << " " << s << " " << t << endl;
    }

    return 0;
}