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

using namespace std;

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

void take_input_vector(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}

void print_vector_to_debug(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

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

        vector<vector<ll>> nums(n, vector<ll>(m));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> nums[i][j];
            }
        }

        ll ans = 0;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                ll sum = 0;

                ll r = i, c = j;
                while (r >= 0 && c >= 0 && c < m && r < n)
                {
                    sum += nums[r][c];
                    r--;
                    c++;
                }

                r = i, c = j;
                while (r >= 0 && c >= 0 && c < m && r < n)
                {
                    sum += nums[r][c];
                    r++;
                    c--;
                }

                r = i, c = j;
                while (r >= 0 && c >= 0 && c < m && r < n)
                {
                    sum += nums[r][c];
                    r--;
                    c--;
                }

                r = i, c = j;
                while (r >= 0 && c >= 0 && c < m && r < n)
                {
                    sum += nums[r][c];
                    r++;
                    c++;
                }

                sum -= nums[i][j] * 3;
                ans = max(ans, sum);
            }
        }

        cout << ans << endl;
    }

    return 0;
}