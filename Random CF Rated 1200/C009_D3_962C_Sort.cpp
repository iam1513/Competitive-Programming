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
        ll n, q;
        cin >> n >> q;

        string st1, st2;
        cin >> st1 >> st2;

        vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
        vector<vector<int>> pre2(n + 1, vector<int>(26, 0));

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 26; j++)
            {
                pre1[i + 1][j] = pre1[i][j];
                pre2[i + 1][j] = pre2[i][j];
            }

            pre1[i + 1][st1[i] - 'a']++;
            pre2[i + 1][st2[i] - 'a']++;
        }

        while (q--)
        {
            ll l, r;
            cin >> l >> r;

            ll diff = 0;
            for (ll i = 0; i < 26; i++)
            {
                ll v1 = pre1[r][i] - pre1[l - 1][i];
                ll v2 = pre2[r][i] - pre2[l - 1][i];

                diff += abs(v1 - v2);
            }

            cout << diff / 2 << endl;
        }
    }

    return 0;
}