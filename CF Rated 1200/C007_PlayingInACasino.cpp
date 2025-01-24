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

        vector<vector<ll>> matrix(n, vector<ll>(m));

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        ll rows = matrix.size();
        ll cols = matrix[0].size();

        vector<vector<ll>> transposed(cols, vector<ll>(rows));
        for (ll i = 0; i < rows; ++i)
        {
            for (ll j = 0; j < cols; ++j)
            {
                transposed[j][i] = matrix[i][j];
            }
        }

        for (ll i = 0; i < cols; ++i)
        {
            sort(transposed[i].begin(), transposed[i].end());
        }

        ll ans = 0;
        for (ll i = 0; i < m; i++)
        {
            ll sum = transposed[i][0];
            for (ll j = 1; j < n; j++)
            {
                ans += transposed[i][j] * j - sum;
                sum += transposed[i][j];
            }
        }

        cout << ans << endl;
    }

    return 0;
}