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
        vector<char> chs;
        string st = "";
        for (ll i = 1; i <= n; i++)
        {
            if (i % 5 == 1)
            {
                chs.push_back('a');
            }
            if (i % 5 == 2)
            {
                chs.push_back('e');
            }
            if (i % 5 == 3)
            {
                chs.push_back('i');
            }
            if (i % 5 == 4)
            {
                chs.push_back('o');
            }
            if (i % 5 == 0)
            {
                chs.push_back('u');
            }
        }
        sort(chs.begin(), chs.end());

        for (ll i = 0; i < n; i++)
        {
            st += chs[i];
        }

        cout << st << endl;
    }

    return 0;
}