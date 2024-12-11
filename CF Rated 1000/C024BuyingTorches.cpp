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
        ll x, y, k;
        cin >> x >> y >> k;

        // Getting all the coal we needed
        ll coal = y * k;

        // All the sticks we need
        ll sticks = k;

        // No of times we have to perform an operation to get all coal and sticks
        ll ops = (sticks + coal - 1) / (x - 1);

        if ((sticks + coal - 1) % (x - 1) != 0)
        {
            ops = 1 + ops;
        }

        cout << k + ops << endl;
    }

    return 0;
}