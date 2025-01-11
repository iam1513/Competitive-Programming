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
    string st = to_string(n);

    for (ll i = 0; i < st.size(); i++)
    {
        if (st[i] == '5')
        {
            st[i] = '4';
        }
        if (st[i] == '6')
        {
            st[i] = '3';
        }
        if (st[i] == '7')
        {
            st[i] = '2';
        }
        if (st[i] == '8')
        {
            st[i] = '1';
        }
        if (st[i] == '9')
        {
            st[i] = '0';
        }
    }

    cout << st << endl;

    return 0;
}