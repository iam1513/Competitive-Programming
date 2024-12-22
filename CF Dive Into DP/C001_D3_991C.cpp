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
        string st;
        cin >> st;

        ll sum = 0, cnt2 = 0, cnt3 = 0;

        for (ll i = 0; i < st.size(); i++)
        {
            sum += st[i] - '0';
            if (st[i] == '3')
            {
                cnt3++;
            }
            if (st[i] == '2')
            {
                cnt2++;
            }
        }
        bool ans = false;
        for (ll i = 0; i <= min(cnt2, 10LL); i++)
        {
            for (ll j = 0; j <= min(cnt3, 10LL); j++)
            {
                if ((sum + 2 * i + 6 * j) % 9 == 0)
                {
                    ans = true;
                    break;
                }
            }
        }

        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}