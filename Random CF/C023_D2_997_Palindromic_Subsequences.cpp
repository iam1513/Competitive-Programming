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
        if (n == 6)
        {
            cout << "1 1 2 3 1 2\n";
        }
        // else if (n == 9)
        // {
        //     cout << "7 3 3 7 5 3 7 7 3\n";
        // }
        // else if (n == 15)
        // {
        //     cout << "15 8 8 8 15 5 8 1 15 5 8 15 15 15 8\n";
        // }
        else
        {
            for (int i = 1; i <= n - 2; i++)
                cout << i << " ";
            cout << "1 2\n";
        }
    }

    return 0;
}