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

string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}

string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}

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
        ll w, h;
        cin >> w >> h;

        vector<ll> x1, x2, y1, y2;

        ll k;
        cin >> k;
        ll max_diff_x = 0;
        ll mini = LLONG_MIN;
        ll maxi = LLONG_MIN;
        for (ll i = 0; i < k; i++)
        {
            ll a;
            cin >> a;
            mini = min(mini, a);
            maxi = max(maxi, a);
            x1.pb(a);
        }

        max_diff_x = max(max_diff_x, maxi - mini);
        cin >> k;
        mini = LLONG_MIN;
        maxi = LLONG_MIN;
        for (ll i = 0; i < k; i++)
        {
            ll a;
            cin >> a;
            x2.pb(a);
        }
        max_diff_x = max(max_diff_x, maxi - mini);

        cin >> k;
        mini = LLONG_MIN;
        maxi = LLONG_MIN;
        ll max_diff_y = 0;
        for (ll i = 0; i < k; i++)
        {
            ll a;
            cin >> a;
            mini = LLONG_MIN;
            maxi = LLONG_MIN;
            y1.pb(a);
        }

        max_diff_y = max(max_diff_y, maxi - mini);
        cin >> k;
        mini = LLONG_MIN;
        maxi = LLONG_MIN;
        for (ll i = 0; i < k; i++)
        {
            ll a;
            cin >> a;
            mini = LLONG_MIN;
            maxi = LLONG_MIN;
            y2.pb(a);
        }
        max_diff_y = max(max_diff_y, maxi - mini);
    }

    return 0;
}