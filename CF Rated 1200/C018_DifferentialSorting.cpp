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
        ll n;
        cin >> n;

        vll nums(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        if (n == 1) // Handle edge case when n == 1
        {
            cout << nums[0] << endl;
            cout << nums[0] << endl;
            cout << 1 << endl;
            cout << nums[0] << endl;
            cout << 1 << endl;
            continue;
        }

        vll maxi(n), mini(n), maxi_idx(n), mini_idx(n);

        if (nums[n - 1] > nums[n - 2])
        {
            maxi[n - 2] = nums[n - 1];
            maxi_idx[n - 2] = n - 1;
        }
        else
        {
            maxi[n - 2] = nums[n - 2];
            maxi_idx[n - 2] = n - 2;
        }

        if (nums[n - 1] < nums[n - 2])
        {
            mini[n - 2] = nums[n - 1];
            mini_idx[n - 2] = n - 1;
        }
        else
        {
            mini[n - 2] = nums[n - 2];
            mini_idx[n - 2] = n - 2;
        }

        for (ll i = n - 3; i >= 0; i--)
        {
            if (nums[i] > maxi[i + 1])
            {
                maxi[i] = nums[i];
                maxi_idx[i] = i;
            }
            else
            {
                maxi[i] = maxi[i + 1];
                maxi_idx[i] = maxi_idx[i + 1];
            }
        }

        for (ll i = n - 3; i >= 0; i--)
        {
            if (nums[i] < mini[i + 1])
            {
                mini[i] = nums[i];
                mini_idx[i] = i;
            }
            else
            {
                mini[i] = mini[i + 1];
                mini_idx[i] = mini_idx[i + 1];
            }
        }

        for (ll i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;

        for (ll i = 0; i < n; i++)
        {
            cout << maxi[i] << " ";
        }
        cout << endl;

        for (ll i = 0; i < n; i++)
        {
            cout << maxi_idx[i] << " ";
        }
        cout << endl;

        for (ll i = 0; i < n; i++)
        {
            cout << mini[i] << " ";
        }
        cout << endl;

        for (ll i = 0; i < n; i++)
        {
            cout << mini_idx[i] << " ";
        }
        cout << endl;

        ll ans = 0, cnt = 0;
        vector<vector<ll>> col;
        for (ll i = 0; i < n - 2; i++)
        {
            ll to_put = min(min(maxi[i] - mini[i], mini[i] - maxi[1]), nums[i]);
            if (to_put > nums[i + 1])
            {
                break;
            }
            if (to_put != nums[i])
            {
                ll x = i + 1, y = 0, z = 0;
                if (maxi[i] - mini[i] > mini[i] - maxi[i])
                {
                    y = mini_idx[i], z = maxi_idx[i];
                }
                else
                {
                    z = mini_idx[i], y = maxi_idx[i];
                }

                ans++;
                col.push_back({x, y, z});
            }
            {
                cnt++;
            }
        }
        if (!col.size() && !cnt)
        {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
        for (ll i = 0; i < col.size(); i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                cout << col[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
