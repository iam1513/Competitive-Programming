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

void recom()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll ss, pp;
    ss = pp = 0;

    ll si = 0;
    ll pi = -1;

    ll idx = 0;

    for (auto &i : s)
    {
        if (i == 's')
        {
            ss++;
            si = idx;
        }
        if (i == 'p')
        {
            pp++;
            if (pi == -1)
            {
                pi = idx;
            }
        }
        idx++;
    }

    if (ss == 0 || pp == 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (si == 0 || pi == n - 1)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        recom();
    }

    return 0;
}