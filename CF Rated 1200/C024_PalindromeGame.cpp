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

bool palindrome(string st)
{

    ll i = 0, j = st.size() - 1;
    bool flag = true;

    while (i < j)
    {
        if (st[i] != st[j])
        {
            flag = false;
            break;
        }
    }

    return flag;
}

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

        string st;
        cin >> st;

        ll zeros = 0;

        for (ll i = 0; i < n; i++)
        {
            zeros += st[i] == '0';
        }

        if (zeros == 1)
        {
            cout << "BOB\n";
            continue;
        }

        if (zeros % 2)
        {
            cout << "ALICE\n";
            continue;
        }

        cout << "BOB\n";
    }

    return 0;
}