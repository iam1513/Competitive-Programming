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
        ll n, m;
        cin >> n >> m;

        vector<vector<char>> a(n + 1, vector<char>(m + 1)); // 1-based indexing
        vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));

        // Read input
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
            }
        }

        // Mark row prefixes
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= m; ++j)
            {
                if (a[i][j] == '0')
                    break;
                vis[i][j] = true;
            }
        }

        // Mark column prefixes
        for (ll j = 1; j <= m; ++j)
        {
            for (ll i = 1; i <= n; ++i)
            {
                if (a[i][j] == '0')
                    break;
                vis[i][j] = true;
            }
        }

        // Check if all '1's are covered
        bool fl = true;
        for (ll i = 1; i <= n && fl; ++i)
        {
            for (ll j = 1; j <= m; ++j)
            {
                if (a[i][j] == '1' && !vis[i][j])
                {
                    fl = false;
                    break;
                }
            }
        }

        cout << (fl ? "YES" : "NO") << "\n";
    }

    return 0;
}