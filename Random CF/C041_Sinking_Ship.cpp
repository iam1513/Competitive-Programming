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

    ll n;
    cin >> n;

    vector<string> rats, ws, m, c;

    while (n--)
    {
        string st1, st2;
        cin >> st1 >> st2;

        if (st2 == "rat")
        {
            rats.push_back(st1);
        }
        if (st2 == "woman" || st2 == "child")
        {
            ws.push_back(st1);
        }
        if (st2 == "man")
        {
            m.push_back(st1);
        }
        if (st2 == "captain")
        {
            c.push_back(st1);
        }
    }

    for (ll i = 0; i < rats.size(); i++)
    {
        cout << rats[i] << endl;
    }

    for (ll i = 0; i < ws.size(); i++)
    {
        cout << ws[i] << endl;
    }

    for (ll i = 0; i < m.size(); i++)
    {
        cout << m[i] << endl;
    }

    for (ll i = 0; i < c.size(); i++)
    {
        cout << c[i] << endl;
    }

    return 0;
}