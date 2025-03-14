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

    string st;
    cin >> st;

    ll cnt1 = 0, cnt2 = 0;

    for (ll i = 0; i < st.size(); i++)
    {
        if (st[i] == '1')
        {
            cnt1++;
            cnt2 = 0;
            if (cnt1 == 7)
            {
                break;
            }
        }

        if (st[i] == '0')
        {
            cnt2++;
            cnt1 = 0;
            if (cnt2 == 7)
            {
                break;
            }
        }
    }

    if (cnt1 == 7 || cnt2 == 7)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}