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

bool checkString(const string &a)
{
    int n = a.length();

    if (a.find("111") != string::npos)
        return true;
    if (a.find("11") != string::npos && a.find("11", a.find("11") + 1) != string::npos)
        return true;
    if (a.find("11") != string::npos && (a[0] == '1' || a[n - 1] == '1'))
        return true;
    if (a[0] == '1' && a[n - 1] == '1')
        return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        int n;
        string a;
        cin >> n >> a;

        if (checkString(a))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}