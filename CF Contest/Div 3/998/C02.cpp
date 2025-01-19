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

        // if (n == 1 && m == 1)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }

        vector<vector<ll>> nums(n, vector<ll>(m, 0));

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> nums[i][j];
            }
        }

        for (ll i = 0; i < n; ++i)
        {
            sort(nums[i].begin(), nums[i].end());
        }

        vector<pair<ll, ll>> pair;
        for (ll i = 0; i < n; i++)
        {
            pair.push_back({nums[i][0], i + 1});
        }

        sort(pair.begin(), pair.end());

        // for (ll i = 0; i < pair.size(); i++)
        // {
        //     cout << " first " << pair[i].first << " second " << pair[i].second << endl;
        // }

        vll rows;
        for (ll i = 0; i < pair.size(); i++)
        {
            rows.push_back(pair[i].second);
        }

        bool flag = true;
        for (ll i = 0; i < n; i++)
        {
            ll r = rows[i];
            for (ll j = 0; j < m - 1; j++)
            {
                if (nums[r - 1][j] + n != nums[r - 1][j + 1])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }

        if (flag)
        {
            for (ll i = 0; i < rows.size(); i++)
            {
                cout << rows[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}