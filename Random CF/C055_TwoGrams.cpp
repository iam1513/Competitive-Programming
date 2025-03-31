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

    string s;
    cin >> s;

    string ans;

    ll cnt = 0;

    for (ll i = 0; i < n; i++)
    {
        string st = s.substr(i, 2);
        ll cnt_l = 0;
        for (ll j = i; j < n; j++)
        {
            string st1 = s.substr(j, 2);
            // cout << st1 << endl;
            if (st == st1)
            {
                // cout << "HERE" << endl;
                cnt_l++;
            }
        }
        // cout << i << " " << cnt_l << endl;
        if (cnt_l > cnt)
        {
            cnt = cnt_l;
            ans = st;
        }
    }

    cout << ans << endl;

    return 0;
}